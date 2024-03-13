#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib> // For std::rand and std::srand
#include <ctime>   // For std::time
#include <thread>  // For std::this_thread::sleep_for
#include <chrono>  // For std::chrono::millisecon
using namespace std;
int generate_rand_limit(int minRange, int maxRange){
    
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    // Generate a random number within the specified range
    int randomNumber = minRange + std::rand() % (maxRange - minRange + 1);
    
    std::this_thread::sleep_for(std::chrono::milliseconds(1237));

    return randomNumber;
}

struct Router{
    int address; //key
    int ports{10};
    int cpu{10};
};

int main() {
    //fill the list of Router
    std::vector<Router> vec;
    for(int i = 0; i< 10; i++){
        int address = i; // unique address
        int ports = generate_rand_limit(1,10);
        int cpu = generate_rand_limit(1,100);
        vec.push_back({address,ports,cpu});
        std::cout << "[Ports,cpu]:"<< ports << ","<< cpu <<std::endl;
    }
    std::cout << "creating Heap"  << std::endl;

    // Define a custom lambda function to compare two integers in ascending order
    auto min_compare = [](Router a, Router b) { 
        if(a.ports > b.ports) // lower value of port will be on top
            return true;
        else if(a.ports == b.ports && a.cpu > b.cpu) // if ports are same then min heap using cpu
            return true;
        return false;
    };

    auto max_compare = [](Router a, Router b) { 
        if(a.ports < b.ports) // higher value of port will be on top
            return true;
        else if(a.ports == b.ports && a.cpu < b.cpu) // if ports are same then max heap using cpu
            return true;
        return false;
    };
    
    // Declare a min heap (priority queue) with custom comparison lambda
    //std::priority_queue<int, std::vector<int>, decltype(compare)> minHeap(compare);
    std::priority_queue minHeap(vec.begin(),vec.end(),min_compare);
    std::priority_queue maxHeap(vec.begin(),vec.end(),max_compare);
        
    cout << "min heap Most utilized-----------" << endl << endl;
    while (!minHeap.empty()) {
        cout << minHeap.top().address <<"[Ports,cpu]:" << minHeap.top().ports << "," << minHeap.top().cpu << endl;
        minHeap.pop();
    }

    cout << "Max heap Least utilized----------" << endl << endl;
    while (!maxHeap.empty()) {
        cout << maxHeap.top().address <<"[Ports,cpu]:" << maxHeap.top().ports << "," << maxHeap.top().cpu << endl;
        maxHeap.pop();
    }

    return 0;
}
