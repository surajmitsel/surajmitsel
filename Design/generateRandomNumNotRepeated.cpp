#include <iostream>
#include <cstdlib> // For std::rand and std::srand
#include <ctime>   // For std::time
#include <unordered_set>

int main() {
    // Seed the random number generator with the current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Define the range of random numbers
    int minRange = 1;
    int maxRange = 1000;

    // Initialize an unordered set to store the recently generated numbers
    std::unordered_set<int> recent;

    // Generate a random number within the specified range
    int randomNumber;
    do {
        randomNumber = minRange + std::rand() % (maxRange - minRange + 1);
    } while (recent.count(randomNumber) > 0); // Repeat until a non-repeated number is found

    // Add the generated number to the set of recent numbers
    recent.insert(randomNumber);

    std::cout << "Random number [" << minRange << ", " << maxRange << "]: " << randomNumber << std::endl;

    return 0;
}
