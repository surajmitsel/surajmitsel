#include <iostream>
#include <thread>
#include <semaphore>

std::binary_semaphore sem(0); // Semaphore with initial count 0

void threadA() {
    std::cout << "Thread A is waiting for Thread B to signal\n";
    sem.acquire(); // Wait for Thread B to signal
    std::cout << "Thread A received signal from Thread B\n";
}

void threadB() {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate some work
    std::cout << "Thread B is signaling Thread A\n";
    sem.release(); // Signal Thread A
}

int main() {
    std::thread t1(threadA);
    std::thread t2(threadB);

    t1.join();
    t2.join();

    return 0;
}