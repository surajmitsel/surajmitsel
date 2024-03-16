#include <iostream>
#include <thread>
#include <chrono>

// Function to be executed in a separate thread
int threadFunction(int a, int b) {
    // Simulate some time-consuming computation
    std::this_thread::sleep_for(std::chrono::seconds(2));
    return a + b;
}

int main() {
    int arg1 = 10;
    int arg2 = 20;

    // Create a thread and pass arguments using a lambda function
    std::thread t([&]() {
        int result = threadFunction(arg1, arg2);
        std::cout << "Result from thread: " << result << std::endl;
    });

    // Main thread continues execution while the child thread runs concurrently
    std::cout << "Main thread continues execution..." << std::endl;

    // Wait for the thread to finish its execution
    t.join();

    return 0;
}
