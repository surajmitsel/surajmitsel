#include <iostream>
#include <thread>
#include <vector>

// std::ref needs to be used

// Function that takes a vector by reference and modifies it
void modifyVector(std::vector<int>& vec) {
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i); // Modify the vector
    }
    // Print the contents of the modified vector
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> myVector;

    // Create a thread and pass a reference to the vector
    std::thread t(modifyVector, std::ref(myVector));

    // Wait for the thread to finish
    t.join();

    // Print the contents of the modified vector in the main thread
    for (int num : myVector) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
