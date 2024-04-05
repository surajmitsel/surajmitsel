#include <iostream>
#include <string>
#include <sstream>
/*
 A [1,   126]
 B [128, 191]
 C [192, 223]
 D [224, 239]
 E [240, 255]

*/
bool isValidIPAddressForClass(const std::string& ipAddress, char ipClass) {
    // Determine the class of the IP address
    char detectedClass = 'E'; // Default value indicating error or not an IPv4 address
    std::istringstream iss(ipAddress);
    int firstOctet;
    char dot;
    iss >> firstOctet >> dot;

    if (firstOctet >= 1 && firstOctet <= 126) {
        detectedClass = 'A';
    } else if (firstOctet >= 128 && firstOctet <= 191) {
        detectedClass = 'B';
    } else if (firstOctet >= 192 && firstOctet <= 223) {
        detectedClass = 'C';
    } else if (firstOctet >= 224 && firstOctet <= 239) {
        detectedClass = 'D';
    } else if (firstOctet >= 240 && firstOctet <= 255) {
        detectedClass = 'E';
    }

    // Check if the detected class matches the expected class
    return detectedClass == ipClass;
}

int main() {
    std::string ipAddress;
    char ipClass;

    std::cout << "Enter an IP address: ";
    std::cin >> ipAddress;
    std::cout << "Enter the expected IP class (A, B, C, D, or E): ";
    std::cin >> ipClass;

    if (isValidIPAddressForClass(ipAddress, ipClass)) {
        std::cout << "The IP address is valid for class " << ipClass << "." << std::endl;
    } else {
        std::cout << "The IP address is not valid for class " << ipClass << "." << std::endl;
    }

    return 0;
}
