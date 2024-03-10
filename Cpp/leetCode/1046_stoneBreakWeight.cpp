#include <queue>
#include <vector>
#include <iostream>
using namespace std;
/*
1046. Last Stone Weight
Easy

You are given an array of integers stones where stones[i] is the weight of the ith stone.

We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. 
Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:

If x == y, both stones are destroyed, and
If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
At the end of the game, there is at most one stone left.

Return the weight of the last remaining stone. If there are no stones left, return 0.

 

Example 1:

Input: stones = [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of the last stone.
Example 2:

Input: stones = [1]
Output: 1
 

Constraints:

1 <= stones.length <= 30
1 <= stones[i] <= 1000
*/

int lastStoneWeight_1(std::vector<int>& stones) {
    //priority queue (max heap by default on top always high it will be) 
    std::priority_queue<int> pq(stones.begin(), stones.end());
    while (pq.size() > 1) {
        int stone1 = pq.top(); pq.pop();
        int stone2 = pq.top(); pq.pop();
        int result = std::abs(stone1 - stone2);
        if (result > 0) {
            pq.push(result);
        }
    }
    return pq.empty() ? 0 : pq.top();
}

int lastStoneWeight_2(std::vector<int>& stones) {
    std::make_heap(stones.begin(),stones.end());
    
    while (stones.size() > 1) {
        pop_heap(stones.begin(),stones.end());
        int stone1 = stones.back(); //largest stone1
        stones.pop_back();

        pop_heap(stones.begin(),stones.end());
        int stone2 = stones.back(); //largest stone2d
        stones.pop_back();

        int result = std::abs(stone1 - stone2);
        if (result > 0) {
            stones.push_back(result);
            push_heap(stones.begin(),stones.end()); // heapify again
        }
    }
    return (stones.size() == 0) ? 0 : stones[0];
}

int main() {
    // Test case
    std::vector<int> stones = {2, 7, 4, 1, 8, 1};

    // Call the lastStoneWeight function and display the result
    std::cout << "lastStoneWeight_1: " << lastStoneWeight_1(stones) << std::endl;
    std::cout << "lastStoneWeight_2: " << lastStoneWeight_1(stones) << std::endl;

    return 0;
}