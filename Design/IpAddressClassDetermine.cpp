#include <iostream>
#include <string>
#include <sstream>

char determineClass_1(const std::string& ipAddress) {
    // Find the position of the first dot
    size_t dotPos = ipAddress.find('.');
    if (dotPos == std::string::npos) {
        return 'E'; // Error or invalid IP
    }
    
    // Extract the first octet
    int firstOctet = std::stoi(ipAddress.substr(0, dotPos));
    
    // Determine the class based on the first octet
    if (firstOctet >= 1 && firstOctet <= 126) {
        return 'A';
    } else if (firstOctet >= 128 && firstOctet <= 191) {
        return 'B';
    } else if (firstOctet >= 192 && firstOctet <= 223) {
        return 'C';
    } else if (firstOctet >= 224 && firstOctet <= 239) {
        return 'D';
    } else if (firstOctet >= 240 && firstOctet <= 255) {
        return 'E';
    }
    
    return 'E'; // Error or not an IPv4 address
}

char determineClass_2(const std::string& ipAddress) {
    std::istringstream iss(ipAddress);
    int firstOctet;
    char dot;
    iss >> firstOctet >> dot;

    if (firstOctet >= 1 && firstOctet <= 126) {
        return 'A';
    } else if (firstOctet >= 128 && firstOctet <= 191) {
        return 'B';
    } else if (firstOctet >= 192 && firstOctet <= 223) {
        return 'C';
    } else if (firstOctet >= 224 && firstOctet <= 239) {
        return 'D';
    } else if (firstOctet >= 240 && firstOctet <= 255) {
        return 'E';
    }

    return 'E'; // Error or not an IPv4 address
}

int main() {
    std::string ipAddress = "192.168.10.5";
    // std::cout << "Enter an IP address: ";
    // std::cin >> ipAddress;

    char ipClass = determineClass_2(ipAddress);
    if (ipClass == 'E') {
        std::cout << "Invalid IP address or Error in determining the class." << std::endl;
    } else {
        std::cout << "The IP address is Class " << ipClass << "." << std::endl;
    }

    return 0;
}
