#include <iostream>
#include <vector>
#include <limits>

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int x) : data(x), left(nullptr), right(nullptr) {}
};

// Utility to insert nodes in the BST
Node* insert(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}

// Preorder traversal
void preorder(Node* root, std::vector<int>& result) {
    if (root != nullptr) {
        result.push_back(root->data);
        preorder(root->left, result);
        preorder(root->right, result);
    }
}

// Inorder traversal
void inorder(Node* root, std::vector<int>& result) {
    if (root != nullptr) {
        inorder(root->left, result);
        result.push_back(root->data);
        inorder(root->right, result);
    }
}

// Postorder traversal
void postorder(Node* root, std::vector<int>& result) {
    if (root != nullptr) {
        postorder(root->left, result);
        postorder(root->right, result);
        result.push_back(root->data);
    }
}

// Function to reconstruct BST from preorder traversal
Node* buildBSTFromPreorder(std::vector<int>& preorder, int& index, int min, int max) {
    if (index >= preorder.size())
        return nullptr;

    int key = preorder[index];
    if (key < min || key > max)
        return nullptr;

    Node* root = new Node(key);
    index++;
    root->left = buildBSTFromPreorder(preorder, index, min, key);
    root->right = buildBSTFromPreorder(preorder, index, key, max);
    return root;
}

// Function to reconstruct BST from postorder traversal
Node* buildBSTFromPostorder(std::vector<int>& postorder, int& index, int min, int max) {
    if (index < 0)
        return nullptr;

    int key = postorder[index];
    if (key < min || key > max)
        return nullptr;

    Node* root = new Node(key);
    index--;
    root->right = buildBSTFromPostorder(postorder, index, key, max);
    root->left = buildBSTFromPostorder(postorder, index, min, key);
    return root;
}

// Helper function to compare if two vectors are the same
bool isSame(const std::vector<int>& v1, const std::vector<int>& v2) {
    return v1 == v2;
}

int main() {
    // Example inputs for different cases
    std::vector<int> preorderInput = {8, 5, 1, 7, 10, 9, 12};
    std::vector<int> inorderInput = {1, 5, 7, 8, 9, 10, 12}; // Example inorder input
    std::vector<int> postorderInput = {1, 7, 5, 9, 12, 10, 8}; // Example postorder input
    std::vector<int> result;

    // Test for Preorder
    int preIndex = 0;
    Node* root = buildBSTFromPreorder(preorderInput, preIndex, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    preorder(root, result);
    std::cout << "Preorder reconstruction gives the same sequence: " << isSame(preorderInput, result) << std::endl;

    result.clear();
    inorder(root, result);
    std::cout << "Checking constructed tree with inorder: " << isSame(inorderInput, result) << std::endl;

    result.clear();

    // Test for Postorder
    int postIndex = postorderInput.size() - 1;
    root = buildBSTFromPostorder(postorderInput, postIndex, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    postorder(root, result);
    std::cout << "Postorder reconstruction gives the same sequence: " << isSame(postorderInput, result) << std::endl;

    result.clear();
    inorder(root, result);
    std::cout << "Checking constructed tree with inorder: " << isSame(inorderInput, result) << std::endl;

    return 0;
}
