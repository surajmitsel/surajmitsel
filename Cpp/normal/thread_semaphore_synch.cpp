#include <iostream>
#include <thread>
#include <semaphore>

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

std::binary_semaphore sem(0); // Semaphore with initial count 0 // already not available

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
/*
Thread A is waiting for Thread B to signal
Thread B is signaling Thread A
Thread A received signal from Thread B
*/