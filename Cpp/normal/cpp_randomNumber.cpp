#include <iostream>
#include <cstdlib> // For std::rand and std::srand
#include <ctime>   // For std::time
#include <thread>  // For std::this_thread::sleep_for
#include <chrono>  // For std::chrono::millisecon

void generate_rand_limit(){
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Define the range of random numbers
    int minRange = 1;
    int maxRange = 100;

    // Generate a random number within the specified range
    int randomNumber = minRange + std::rand() % (maxRange - minRange + 1);
    
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    std::cout << "Random number within range [" << minRange << ", " << maxRange << "]: " << randomNumber << std::endl;
}

void generate_rand_withoutlimit(){
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Generate a random number between 0 and RAND_MAX
    int randomNumber = std::rand();

    std::cout << "Random number: " << randomNumber << std::endl;
}
int main() {
    generate_rand_limit();
    generate_rand_withoutlimit();


    return 0;
}
