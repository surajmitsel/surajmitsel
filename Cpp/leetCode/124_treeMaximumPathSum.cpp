/*
124. Binary Tree Maximum Path Sum
Hard.

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence 
has an edge connecting them. A node can only appear in the sequence at most once.
 Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path. 

Example 1:

            1
        2       3

Input: root = [1,2,3]
Output: 6
Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

Example 2:

            -10
          9      20
               15  7

Input: root = [-10,9,20,null,null,15,7]
Output: 42
Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.
*/

/*
solve:
        root
    left     right

Three possible paths
    1. letf t1
    2. right t2
    3. root included

max[
    d1, 
    d2, 
    root.val + max(h1,0) + max(h2,0)
    ]
*/
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
typedef TreeNode* NODE;

int context = 0;
// METHOD1
int maxPathDown_1(NODE root, int& maxSum) {
    cout << " context:----->" << context++ << endl;; 
    if (!root) 
        return 0;
    
    int left = std::max(0, maxPathDown_1(root->left, maxSum));
    int right = std::max(0, maxPathDown_1(root->right, maxSum));

    maxSum = std::max(maxSum, left + right + root->val); // updating always max sum (left + right + root)
    
    return std::max(left, right) + root->val; // returing max(left,right) + root
}
int maxPathSum_1(NODE root) {
    int maxSum = INT_MIN;
    maxPathDown_1(root, maxSum);
    return maxSum;
}

//METHOD2
int maxPathDown_2(NODE root, int& maxSum){
    if(root == nullptr)
        return INT_MIN;

    int h1 = INT_MIN;
    int h2 = INT_MIN;

    int d1 = maxPathDown_2(root->left, h1);
    int d2 = maxPathDown_2(root->right, h2);

    maxSum = max({h1,h2,0}) + root->val;

    return max({d1, d2, max(h1,0) + max(h2,0) + root->val});
}
int maxPathSum_2(NODE root) {
    int maxSum = INT_MIN;
    return maxPathDown_2(root, maxSum);
}

// Example usage:
int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    std::cout << maxPathSum_1(root) << std::endl; // Output: 6
    //std::cout << maxPathSum_2(root) << std::endl; // Output: 6

    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
