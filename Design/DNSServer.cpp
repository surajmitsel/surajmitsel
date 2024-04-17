#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <map>

using namespace std;

// Define DNS database (domain to IP mapping)
map<string, string> dnsDatabase = {
    {"example.com", "192.168.1.100"},
    {"example.org", "192.168.1.101"},
    {"example.net", "192.168.1.102"}
};

// Function to resolve DNS queries
string resolveDNS(const string& domain) {
    auto it = dnsDatabase.find(domain);
    if (it != dnsDatabase.end()) {
        return it->second; // Return IP address if domain found in the database
    } else {
        return "Unknown"; // Return "Unknown" if domain not found
    }
}

int main() {
    // Create a UDP socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        cerr << "Error in socket creation" << endl;
        return 1;
    }

    // Bind the socket to port 53 (standard port for DNS)
    struct sockaddr_in serverAddr;
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(53); // DNS port
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sockfd, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        cerr << "Error in binding" << endl;
        return 1;
    }

    cout << "DNS server is running..." << endl;

    // Loop to receive and handle DNS queries
    while (true) {
        struct sockaddr_in clientAddr;
        socklen_t clientAddrLen = sizeof(clientAddr);
        char buffer[1024];

        // Receive DNS query
        ssize_t recvLen = recvfrom(sockfd, buffer, sizeof(buffer), 0,
                                   (struct sockaddr *)&clientAddr, &clientAddrLen);
        if (recvLen < 0) {
            cerr << "Error in receiving" << endl;
            continue;
        }

        // Convert received data to string
        string domain(buffer, recvLen);

        // Resolve DNS query
        string ip = resolveDNS(domain);

        // Send DNS response
        sendto(sockfd, ip.c_str(), ip.length(), 0,
               (struct sockaddr *)&clientAddr, clientAddrLen);
    }

    // Close the socket
    close(sockfd);

    return 0;
}
