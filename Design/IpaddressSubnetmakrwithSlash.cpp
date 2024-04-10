#include <iostream>
#include <sstream>
#include <string>
using namespace std;

static unsigned int ipToInt(const std::string &ip) {
    unsigned int v = 0;
    std::istringstream iss(ip);
    unsigned int a, b, c, d;
    char dot;
    iss >> a >> dot >> b >> dot >> c >> dot >> d;
    v = a << 24 | b << 16 | c << 8 | d;
    return v;
}

static std::string intToIp(unsigned int ip) {
    std::ostringstream oss;
    oss << ((ip >> 24) & 0xFF) << '.'
        << ((ip >> 16) & 0xFF) << '.'
        << ((ip >> 8) & 0xFF) << '.'
        << (ip & 0xFF);
    return oss.str();
}

void PrintNetworkIDAndHostId(std::string ip, int prefixLength) {
    // Convert IP address to integer representation
    unsigned int ipInt = ipToInt(ip);

    // Calculate subnet mask
    unsigned int subnetMask = 0xFFFFFFFF << (32 - prefixLength);

    // Perform bitwise AND operation to find network ID
    unsigned int networkIDInt = ipInt & subnetMask;
    unsigned int hostIDInt = ipInt & ~subnetMask;

    // Convert network ID back to string format
    std::string networkID = intToIp(networkIDInt);
    std::string hostID = intToIp(hostIDInt);

    std::cout << "Network ID: " << networkID << std::endl;
    std::cout << "Host ID: " << hostID << std::endl;
}

int main() {
    std::string ipAddress = "192.168.10.215/24";

    // Split IP address and prefix length
    size_t pos = ipAddress.find('/');
    std::string ip = ipAddress.substr(0, pos);
    int prefixLength = std::stoi(ipAddress.substr(pos + 1));

    PrintNetworkIDAndHostId(ip, prefixLength);

    return 0;
}
