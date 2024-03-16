#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <queue>
#include <iomanip>

/*
Author: Suraj Kumar Verma
mailId: surajverma.job@gmail.com
*/

using namespace std;
std::mutex inst_mutx;
namespace TIME_CALC
{
    const int window_interval = 5000;
    const int valid_gap = 1500;

    std::chrono::milliseconds getMillSecValFromString(const std::string& timeStr) {
        // time in format s14:55:06.756
        std::istringstream ss(timeStr);
        int hours, minutes, seconds, milliseconds;
        char ignoreColon;
        ss >> hours >> ignoreColon >> minutes >> ignoreColon >> seconds >> ignoreColon >> milliseconds;
        return std::chrono::milliseconds((hours * 3600 + minutes * 60 + seconds) * 1000 + milliseconds);
    }

    int get_time_diff_ms(std::string& time1, std::string& time2){
        auto t1 = getMillSecValFromString(time1);
        auto t2 = getMillSecValFromString(time2);

        // time difference in milliseconds
        if(t1.count() > t2.count()){
            auto timeDiffMillis = t1 - t2;
            return timeDiffMillis.count();
        }else{
            return 0;
        }
    }
}// end namespace TIME_CALC


struct TelmetryData {
    struct DataObj{
        std::string date;
        std::string time;
        vector<double> value{0,0,0}; //kW, V, I
    };
    const unsigned int index_kw = 0;
    const unsigned int index_v = 1;
    const unsigned int index_i = 2;
    const double min_kw = 0.0;
    const double min_v = 475.0;
    const double max_v = 485.0;
    const double min_i = 0.0;
    DataObj data; // Telemetry attributes

    bool validate_data()
    {
        int valid = true;

        if(data.value[index_kw] < min_kw){
            cout << "*Anomaly - Invalid KW value "; 
            valid = false;
        }

        if(data.value[index_v] > max_v || data.value[1] < min_v ){
            cout << "*Anomaly - Invalid V value "; 
            valid = false;
        }

        if(data.value[index_i] < min_i ){
            cout << "*Anomaly - Invalid I value "; 
            valid = false;
        }
        
        if(!valid){
            print_data();
        }
        
        return valid;
    }

    void print_data(){
        std::cout << data.date << " " << data.time << ", " << data.value[index_kw] << ", " << data.value[index_v] << ", " << data.value[index_i];
        std::cout<< std::endl;
    }

    void print_data(vector<double> & avg){
        std::cout << data.date << " " << data.time << ", " << data.value[index_kw] << ", " << data.value[index_v] << ", " <<data.value[index_i];
        cout << ", " << avg[index_kw];
        cout << ", " << avg[index_v];
        cout << ", " << avg[index_i];
        std::cout<< std::endl;
    }

    bool validate_time_gap(string& prev_time) {
        int valid = true;
        int time_diff = TIME_CALC::get_time_diff_ms(data.time, prev_time);
        if(time_diff > TIME_CALC::valid_gap || time_diff == 0){
            cout << "*Anomaly - time gap detected "; 
            valid = false;
        }
        
        if(!valid){
            print_data();
        }
        return valid;
    }
};

class telemetryManager{
    static telemetryManager * instance;
    telemetryManager(){}
    vector<TelmetryData> data_vec;
   
public:
    ~telemetryManager(){delete instance;}
    static telemetryManager *getInstance() {
        if(instance == nullptr) {
            inst_mutx.lock();
            if(instance == nullptr) {
                return instance = new telemetryManager();
            }
            inst_mutx.unlock();
        }
        return instance;
    }
    
    vector<double> calcSlidingWindowAverage(std::queue<TelmetryData>& window) {
        double sum_v1 = 0.0;
        double sum_v2 = 0.0;
        double sum_v3 = 0.0;
        int size = window.size();
        vector<double> avg;
        
        while(!window.empty()) {
            auto tel = window.front();
            sum_v1 += tel.data.value[0];
            sum_v2 += tel.data.value[1];
            sum_v3 += tel.data.value[2];
            window.pop(); // remove all the elements
        }
        avg.push_back(sum_v1/size);
        avg.push_back(sum_v2/size);
        avg.push_back(sum_v3/size);

        return avg;
    }

    vector<TelmetryData>& get_data_list(){
        return data_vec;
    }

    bool read_data_from_file(){
        bool ret_val =  true;
        std::ifstream file("telemetry.dat");

        // Check if the file opened successfully
        if (!file.is_open()) {
            std::cerr << "ERROR: File is not opening." << std::endl;
            ret_val = false;
            return ret_val;
        }

        // Read data from the file
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream stringStream(line);
            TelmetryData cur_data;
            char ignoreChar;
            stringStream >> cur_data.data.date >> cur_data.data.time >> ignoreChar >> cur_data.data.value[cur_data.index_kw] >> ignoreChar >> cur_data.data.value[cur_data.index_v] >> ignoreChar >> cur_data.data.value[cur_data.index_i];
            cur_data.data.time.erase(std::remove(cur_data.data.time.begin(), cur_data.data.time.end(), ','), cur_data.data.time.end());
            if (!stringStream) {
                std::cerr << "ERROR: Invalid line with data: " << line << std::endl;
                continue;
            }
            data_vec.push_back(cur_data);
        }

        // Close the file
        file.close();
        return ret_val;
    };

    void print_all_data(){
        for (const auto& data :data_vec) {
            std::cout << data.data.date << " " << data.data.time << ", " << data.data.value[0] << ", " << data.data.value[1] << ", " << data.data.value[2] << std::endl;
        }
    }    
};
telemetryManager* telemetryManager:: instance{nullptr};



int main() {
    // Open file 
    std::ifstream file("telemetry.dat");

    // Check if the file opened successfully
    if (!file.is_open()) {
        std::cerr << "ERROR: Could not open the file." << std::endl;
        return 1;
    }

    if(telemetryManager::getInstance()->read_data_from_file()){
        //telemetryManager::getInstance()->print_all_data();
        queue<TelmetryData> data_queue;
        auto& all_data = telemetryManager::getInstance()->get_data_list();
        string prev_time{};

        for(auto tel_data: all_data)
        {
            if(data_queue.empty()) {
                data_queue.push(tel_data);
                prev_time = tel_data.data.time;
            }
            else {           
                bool isDataValid = tel_data.validate_data();
                bool isDataValidTmGap = tel_data.validate_time_gap(prev_time);
                bool isAvgWindowExpire = (TIME_CALC::get_time_diff_ms(tel_data.data.time, data_queue.front().data.time) > TIME_CALC::window_interval);
                
                if(isDataValidTmGap && isAvgWindowExpire) {
                    vector<double> avg = telemetryManager::getInstance()->calcSlidingWindowAverage(data_queue);
                    tel_data.print_data(avg);
                }
                
                if(isDataValidTmGap && isDataValid) {   
                    data_queue.push(tel_data);
                    tel_data.print_data();
                }            
                prev_time = tel_data.data.time;
            }
        }
    }else{
        std::cerr << "ERROR: Not able to execute avg calculations" << std::endl;
    }
    return 0;
}
