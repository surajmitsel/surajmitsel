#include <iostream>
#include <bitset>
#include <string>
#include <sstream>

// Function to convert IP address from string to integer
unsigned int ipToInt(const std::string &ip) {
    unsigned int v = 0;
    std::istringstream iss(ip);
    unsigned int a, b, c, d;
    char dot;
    iss >> a >> dot >> b >> dot >> c >> dot >> d;
    v = a << 24 | b << 16 | c << 8 | d;
    return v;
}

// Function to convert IP address from integer to string
std::string intToIp(unsigned int ip) {
    std::ostringstream oss;
    oss << ((ip >> 24) & 0xFF) << '.'
        << ((ip >> 16) & 0xFF) << '.'
        << ((ip >> 8) & 0xFF) << '.'
        << (ip & 0xFF);
    return oss.str();
}

// Function to calculate network and host addresses
void calculateNetworkAndHost(const std::string &ip, const std::string &subnetMask) {
    unsigned int ipInt = ipToInt(ip);
    unsigned int maskInt = ipToInt(subnetMask);
    
    // Calculate network address
    unsigned int networkInt = ipInt & maskInt;
    std::string networkAddress = intToIp(networkInt);
    
    // Calculate host address (using the complement of the subnet mask)
    unsigned int hostInt = ipInt & (~maskInt);
    std::string hostAddress = intToIp(hostInt);

    std::cout << "IP Address: " << ip << std::endl;
    std::cout << "Subnet Mask: " << subnetMask << std::endl;
    std::cout << "Network Address: " << networkAddress << std::endl;
    std::cout << "Host Address: " << hostAddress << std::endl;
}

int main() {
    std::string ip = "192.168.1.10";
    std::string subnetMask = "255.255.255.0";

    calculateNetworkAndHost(ip, subnetMask);

    return 0;
}
/*
IP Address: 192.168.1.10
Subnet Mask: 255.255.255.0
Network Address: 192.168.1.0
Host Address: 0.0.0.10
*/
