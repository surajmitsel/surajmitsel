#include <iostream>
#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Iterative inorder traversal using stack
std::vector<int> inorderTraversal(TreeNode* root) {
    std::vector<int> result;
    std::stack<TreeNode*> stack;
    TreeNode* current = root;

    while (current != nullptr || !stack.empty()) {
        while (current != nullptr) {
            stack.push(current);
            current = current->left;
        }

        current = stack.top();
        stack.pop();
        result.push_back(current->val);
        current = current->right;
    }

    return result;
}

// Iterative preorder traversal using stack
std::vector<int> preorderTraversal(TreeNode* root) {
    std::vector<int> result;
    if (root == nullptr)
        return result;

    std::stack<TreeNode*> stack;
    stack.push(root);

    while (!stack.empty()) {
        TreeNode* current = stack.top();
        stack.pop();
        result.push_back(current->val);

        if (current->right != nullptr)
            stack.push(current->right);
        if (current->left != nullptr)
            stack.push(current->left);
    }

    return result;
}

// Iterative postorder traversal using stack
std::vector<int> postorderTraversal(TreeNode* root) {
    std::vector<int> result;
    if (root == nullptr)
        return result;

    std::stack<TreeNode*> stack;
    stack.push(root);

    while (!stack.empty()) {
        TreeNode* current = stack.top();
        stack.pop();
        result.insert(result.begin(), current->val); // Insert at the beginning to reverse the traversal order

        if (current->left != nullptr)
            stack.push(current->left);
        if (current->right != nullptr)
            stack.push(current->right);
    }

    return result;
}

// Helper function to print vector
void printVector(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Example to demonstrate the traversals

    /*
                1
            2       3
          4    5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    std::cout << "Inorder traversal: ";
    printVector(inorderTraversal(root)); //4 2 5 1 3

    std::cout << "Preorder traversal: ";
    printVector(preorderTraversal(root)); // 1 2 4 5 3 

    std::cout << "Postorder traversal: ";
    printVector(postorderTraversal(root)); // 4 5 2 3 1

    return 0;
}
