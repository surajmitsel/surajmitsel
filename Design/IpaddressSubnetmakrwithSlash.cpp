#include <iostream>
#include <string>
#include <sstream>


using namespace std;


bool validate_ip(string &ip){
    istringstream iss(ip);
    char dot;
    int a,b,c,d;

    iss >> a >> dot >> b >> dot >> c >> dot >> d;
    if(a <0 || a > 255){
        return false;
    }
    if(b <0 || b > 255){
        return false;
    }
    if(c <0 || c > 255){
        return false;
    }
    if(d <0 || d > 255){
        return false;
    }
    return true;
}   

unsigned int IpToInt(const string &ip){
    istringstream iss(ip);
    char dot;
    int a,b,c,d;
    int v =0 ;
    iss >> a >> dot >> b >> dot >> c >> dot >> d;
    v = a << 24 | b << 16 | c << 8 | d;
    return v;
}

string IntToIp(unsigned int intIp){
    ostringstream Ip;
    
    Ip << ((intIp >> 24) & 0xFF) << "."
       << ((intIp >> 16) & 0xFF) << "."
       << ((intIp >> 8) & 0xFF) << "."
       << (intIp & 0xFF);
    
    return Ip.str();
}
void findNetIDHostId(const string &ip, const string &mask){
    unsigned int intIp = IpToInt(ip);
    unsigned int intMask = IpToInt(mask);

    unsigned int netId = intIp & intMask; 
    unsigned int hostId = intIp & ~intMask;
    
    cout << "netId:" << IntToIp(netId) << endl;
    cout << "hostId:" << IntToIp(hostId) << endl;
}

void findNetIDHostId(const string &ip, int maxLen){
    unsigned int intIp = IpToInt(ip);
    unsigned int intMask = 0xFFFFFFFF << (32 - maxLen);

    unsigned int netId = intIp & intMask; 
    unsigned int hostId = intIp & ~intMask;
    
    cout << "netId:" << IntToIp(netId) << endl;
    cout << "hostId:" << IntToIp(hostId) << endl;
}

int main(){
    string ipaddress = "192.132.10.215";
    string subnet_mask = "255.255.255.0";
    cout << validate_ip(ipaddress) << endl;
    findNetIDHostId(ipaddress, subnet_mask);
    
    string ipAddress1 = "192.132.10.215/16";

    auto pos = ipAddress1.find('/');
    string Ip = ipAddress1.substr(0,pos);
    int prefixLength = stoi(ipAddress1.substr(pos+1));
    findNetIDHostId(ipaddress, prefixLength);
}