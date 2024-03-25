#include <iostream>
#include <vector>
#include <algorithm> // for std::sort, std::unique

int main() {
    std::vector<int> nums = {2, 4, 1, 3, 2, 4, 5, 3, 1}; // unsorted

    // Sort the vector to bring duplicates together
    std::sort(nums.begin(), nums.end());

    // Use std::unique to remove consecutive duplicates
    nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

    // Print the vector after removing duplicates
    std::cout << "Vector after removing duplicates: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
