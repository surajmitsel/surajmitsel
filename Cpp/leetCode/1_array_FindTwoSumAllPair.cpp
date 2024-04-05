#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility> // For std::pair
using namespace std;
vector<pair<int, int>> findPairsWithGivenSum(const std::vector<int>& nums, int target) {
    vector<pair<int,int>> vec_result;
    if (nums.size() < 2)
        return vec_result;

    unordered_map<int,int> myMap; // <Value, index>
    
    for(int i = 0; i < nums.size(); i++){
       int val =  nums[i];
       int comp = target - val;
       
       auto it = myMap.find(comp);
       if(it != myMap.end()) { // found
            vec_result.push_back({it->second, i});
            myMap.clear();
       }
       else{
        myMap[val] = i;
       }
    }
    return vec_result;
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
