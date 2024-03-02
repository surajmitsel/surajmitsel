#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

/*
We have a shared buffer implemented as a queue.
We use a mutex (std::mutex) to protect access to the buffer and ensure 
mutual exclusion between the producer and consumer threads.

We use condition variables (std::condition_variable) to synchronize the producer and consumer threads. 
The producer waits if the buffer is full, and the consumer waits if the buffer is empty.
The producer thread generates items and pushes them into the buffer, 
while the consumer thread retrieves items from the buffer and processes them.
Each thread notifies the other thread when an item is produced or consumed, respectively.
*/
const int BUFFER_SIZE = 5;
std::queue<int> buffer;
std::mutex mtx;
std::condition_variable cv_producer, cv_consumer;

void producer() {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv_producer.wait(lock, [] { return buffer.size() < BUFFER_SIZE; }); // Wait if buffer is full
        buffer.push(i);
        std::cout << "Produced item: " << i << std::endl;
        lock.unlock();
        cv_consumer.notify_one(); // Notify consumer that item is available
    }
}

void consumer() {
    for (int i = 0; i < 10; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv_consumer.wait(lock, [] { return !buffer.empty(); }); // Wait if buffer is empty
        int item = buffer.front();
        buffer.pop();
        std::cout << "Consumed item: " << item << std::endl;
        lock.unlock();
        cv_producer.notify_one(); // Notify producer that space is available
    }
}

int main() {
    std::thread producer_thread(producer);
    std::thread consumer_thread(consumer);

    producer_thread.join();
    consumer_thread.join();

    return 0;
}
