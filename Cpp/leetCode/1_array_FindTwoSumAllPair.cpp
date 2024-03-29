#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility> // For std::pair

std::vector<std::pair<int, int>> findPairsWithGivenSum(const std::vector<int>& nums, int target) {
    std::vector<std::pair<int, int>> result;
    std::unordered_map<int, int> hash; // Value -> Index

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];

        if (hash.find(complement) != hash.end()) { // found
            result.push_back({complement, nums[i]});
        }

        // Add current number to the hash map
        hash[nums[i]] = i;
    }

    return result;
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15, -2, 4, 6, 2, 7};
    int target = 9;

    auto pairs = findPairsWithGivenSum(nums, target);

    std::cout << "Pairs with sum " << target << ": ";
    for (const auto& pair : pairs) {
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    std::cout << std::endl;

    return 0;
}
