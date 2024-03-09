#include <iostream>
#include <vector>

using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode* left{nullptr};
    TreeNode* right{nullptr};
    TreeNode(int x) : val(x){}
};

typedef TreeNode* NODE;

void findPaths(NODE root, int targetSum, vector<int>& path, vector<vector<int>>& result) {
    if (root == nullptr) {
        return;
    }
    // Add current node's value to the path
    path.push_back(root->val);
    // If current node is a leaf and its value equals the remaining target sum, add the path to the result
    if (root->left == nullptr && root->right == nullptr && root->val == targetSum) {
        result.push_back(path);
    }
    // Recursively explore left and right subtrees
    findPaths(root->left, targetSum - root->val, path, result);
    findPaths(root->right, targetSum - root->val, path, result);
    
    // Backtrack: Remove current node's value from the path
    path.pop_back();
}

vector<vector<int>> pathSum(NODE root, int targetSum) {
    vector<vector<int>> result;
    vector<int> path;
    findPaths(root, targetSum, path, result);
    return result;
}

// Example usage
int main() {
/*                  
                    5
                4       8
            11       13    4
         7      2         5  1

*/                    
    // Create a binary tree
    NODE root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->right->right->left = new TreeNode(5);
    root->right->right->right = new TreeNode(1);

    int targetSum = 22;
    vector<vector<int>> paths = pathSum(root, targetSum);
    // Output the paths whose sum equals the target sum
    for (const auto& path : paths) {
        cout << "Path: ";
        for (int val : path) {
            cout << val << ",";
        }
        cout << endl;
    }
    /*
    Path: 5,4,11,2,
    Path: 5,8,4,5,
    */

    // Clean up the dynamically allocated memory
    // Note: This step is important to avoid memory leaks
    delete root->right->right->right;
    delete root->right->right->left;
    delete root->right->right;
    delete root->right->left;
    delete root->right;
    delete root->left->left->right;
    delete root->left->left->left;
    delete root->left->left;
    delete root->left;
    delete root;

    return 0;
}