#include <iostream>
#include <thread>
#include <semaphore>

std::binary_semaphore sem(1); // Define a binary semaphore with initial count 1

void printMessage(const std::string& msg, int id) {
    sem.acquire(); // Acquire the semaphore before accessing the shared resource
    std::cout << "Thread " << id << ": " << msg << std::endl;
    sem.release(); // Release the semaphore after accessing the shared resource
}

int main() {
    std::thread t1(printMessage, "Hello from thread 1", 1);
    std::thread t2(printMessage, "Hello from thread 2", 2);

    t1.join();
    t2.join();

    return 0;
}