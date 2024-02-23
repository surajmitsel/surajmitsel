#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx; // Define a mutex

void printMessage(const std::string& msg, int id) {
    mtx.lock(); // Lock the mutex before accessing the shared resource
    std::cout << "Thread " << id << ": " << msg << std::endl;
    mtx.unlock(); // Unlock the mutex after accessing the shared resource
}

int main() {
    std::thread t1(printMessage, "Hello from thread 1", 1);
    std::thread t2(printMessage, "Hello from thread 2", 2);

    t1.join();
    t2.join();

    return 0;
}