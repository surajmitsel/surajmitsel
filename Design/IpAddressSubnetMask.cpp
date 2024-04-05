#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <bitset>

struct IPAddress {
    unsigned int ip;
    unsigned int subnetMask;
    unsigned int networkAddress;
    unsigned int hostAddress;

    // Constructor initializes from strings
    IPAddress(const std::string& ipStr, const std::string& subnetStr) {
        ip = ipToInt(ipStr);
        subnetMask = ipToInt(subnetStr);
        networkAddress = ip & subnetMask;
        hostAddress = ip & ~subnetMask;
    }

    // Converts IP address from string to integer
    static unsigned int ipToInt(const std::string &ip) {
        unsigned int v = 0;
        std::istringstream iss(ip);
        unsigned int a, b, c, d;
        char dot;
        iss >> a >> dot >> b >> dot >> c >> dot >> d;
        v = a << 24 | b << 16 | c << 8 | d;
        return v;
    }

    // Converts IP address from integer to string
    static std::string intToIp(unsigned int ip) {
        std::ostringstream oss;
        oss << ((ip >> 24) & 0xFF) << '.'
            << ((ip >> 16) & 0xFF) << '.'
            << ((ip >> 8) & 0xFF) << '.'
            << (ip & 0xFF);
        return oss.str();
    }
};

int main() {
    std::string ip = "192.168.1.10";
    std::string subnetMask = "255.255.255.0";

    IPAddress address(ip, subnetMask);

    std::cout << "IP Address: " << IPAddress::intToIp(address.ip) << std::endl;
    std::cout << "Subnet Mask: " << IPAddress::intToIp(address.subnetMask) << std::endl;
    std::cout << "Network Address: " << IPAddress::intToIp(address.networkAddress) << std::endl;
    std::cout << "Host Address: " << IPAddress::intToIp(address.hostAddress) << std::endl;

    return 0;
}
/*
IP Address: 192.168.1.10
Subnet Mask: 255.255.255.0
Network Address: 192.168.1.0
Host Address: 0.0.0.10
*/
