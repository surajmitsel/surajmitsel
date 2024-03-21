#include <iostream>
#include <thread>

/*
In C++, a thread starts executing as soon as its associated thread object is created. 
The join() function is used to synchronize the main thread with the completion of the child thread's execution. 
When you call join() on a thread object, the main thread will wait until the child thread finishes 
its execution before continuing further.

So, calling join() after creating the thread ensures that the 
main thread does not proceed until the child thread has completed its execution.
 If join() is not called, the child thread might continue running independently of the main thread, 
 which can lead to unexpected behavior or program termination.
*/

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