### ePoll for muliple connection client connection to the server
Using the epoll method for handling multiple client connections involves several steps. Here's a basic outline of how you can implement it:

- 1. `Create a socket and bind it to a port`: This is similar to setting up a server socket in other methods.

- 2. `Set up epoll`: Create an epoll instance using epoll_create and add the server socket to the epoll instance using epoll_ctl.

- 3. `Wait for events`: Use epoll_wait to wait for events on the epoll instance. This function blocks until one or more events occur on the registered file descriptors.

- 4. `Handle events`: Iterate through the events returned by epoll_wait and handle each event accordingly. For example, if a new client connection is detected, accept the connection and add the new client socket to the epoll instance. If data is available to read on a client socket, read the data and process it. If a client socket is closed or encounters an error, remove it from the epoll instance.

- 5. `Repeat`: Go back to waiting for events and handling them in a loop.

Here's a simplified example in C++ demonstrating how to use epoll for handling multiple client connections:

```cpp
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/epoll.h>

#define PORT 8080
#define MAX_EVENTS 10

int main() {
    int server_fd;
    // 1. Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // 2. Set socket options to allow multiple connections
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // 3. Bind the socket to the specified port and address
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // 4. Listen for incoming connections
    if (listen(server_fd, SOMAXCONN) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // 5. Create epoll instance
    epoll_fd = epoll_create1(0);
    if (epoll_fd == -1) {
        perror("epoll_create1");
        exit(EXIT_FAILURE);
    }

    // Add server socket to epoll instance
    int epoll_fd;
    struct epoll_event event, events[MAX_EVENTS];
    event.events = EPOLLIN;
    event.data.fd = server_fd;
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_fd, &event) == -1) {
        perror("epoll_ctl: server_fd");
        exit(EXIT_FAILURE);
    }

    std::cout << "Server listening on port " << PORT << std::endl;

    // Main event loop
    while (true) {
        int num_events = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        if (num_events == -1) {
            perror("epoll_wait");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < num_events; ++i) {
            int fd = events[i].data.fd;

            // New client connection
            if (fd == server_fd) {
                struct sockaddr_in client_addr;
                socklen_t client_len = sizeof(client_addr);
                int client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
                if (client_fd == -1) {
                    perror("accept");
                    continue;
                }

                std::cout << "New client connected" << std::endl;

                // Add client socket to epoll instance
                event.events = EPOLLIN;
                event.data.fd = client_fd;
                if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_fd, &event) == -1) {
                    perror("epoll_ctl: client_fd");
                    exit(EXIT_FAILURE);
                }
            }
            // Data available to read
            else {
                char buffer[1024];
                ssize_t num_bytes = read(fd, buffer, sizeof(buffer));
                if (num_bytes <= 0) {
                    if (num_bytes == 0) {
                        std::cout << "Client disconnected" << std::endl;
                    } else {
                        perror("read");
                    }

                    // Remove client socket from epoll instance
                    if (epoll_ctl(epoll_fd, EPOLL_CTL_DEL, fd, NULL) == -1) {
                        perror("epoll_ctl: client_fd");
                    }
                    close(fd);
                } else {
                    // Process received data
                    std::cout << "Received from client: " << std::string(buffer, num_bytes) << std::endl;
                }
            }
        }
    }

    // Close server socket and epoll instance (cleanup)
    close(server_fd);
    close(epoll_fd);

    return 0;
}
```
