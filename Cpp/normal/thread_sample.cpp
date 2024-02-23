#include <iostream>
#include <thread>

// Function to be executed by the thread
void threadFunction_1() {
    std::cout << "Thread ID: " << std::this_thread::get_id() << " running_1" << std::endl;
}

void threadFunction_2() {
    std::cout << "Thread ID: " << std::this_thread::get_id() << " running_2" << std::endl;
}

int main() {
    // Creating a thread and passing the function to be executed
    std::thread t1(threadFunction_1);

    std::thread t2(threadFunction_2);

    // Joining the thread with the main thread
    t1.join();
    t2.join();

    // Exiting the main thread
    std::cout << "Main thread exiting" << std::endl;

    return 0;
}