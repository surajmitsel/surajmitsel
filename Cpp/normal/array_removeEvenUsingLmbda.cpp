#include <iostream>
#include <vector>
#include <algorithm> // for std::remove_if

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Use std::remove_if with a lambda predicate to remove even numbers
    nums.erase(std::remove_if(nums.begin(), nums.end(), [](int x) { return x % 2 == 0; }), nums.end());

    // Print the vector after removing even numbers
    std::cout << "Vector after removing even numbers: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
