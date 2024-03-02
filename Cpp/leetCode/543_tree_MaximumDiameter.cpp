#include <algorithm>
#include <iostream>
#include <type_traits>

/*
543. Diameter of Binary Tree
Easy
11.2K
703
Companies
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two
nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges
between them.

          1
        2   3
      4  5

Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Input: root = [1,2]
Output: 1
*/

using namespace std;
struct node {
  int data;
  struct node *left{nullptr};
  struct node *right{nullptr};
  node(int data) : data(data) {}
};

typedef struct node *NODE;

void inorder(struct node *root) {
  if (!root)
    return;
  inorder(root->left);
  cout << root->data << ",";
  inorder(root->right);
}

int maxDepth(NODE root, int& diameter) {
    if (root == nullptr) {
        return 0;
    }
    int leftHeight = maxDepth(root->left, diameter);
    int rightHeight = maxDepth(root->right, diameter);
    diameter = max(diameter, leftHeight + rightHeight); // Update diameter
    return 1 + max(leftHeight, rightHeight); // Return height of subtree rooted at current node
}

int diameterOfBinaryTree(NODE root) {
    if (root == nullptr) {
        return 0;
    }
    int diameter = 0;
    maxDepth(root, diameter);
    return diameter;
}


int main(void) {
  /*
                   1
              2       3
            4   5   6    7
          10               30
        20
  */
  // level traversal: 1,2,3,4,5,6,7,10,20
  struct node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right->left = new node(6);
  root->right->right = new node(7);
  root->right->right->right = new node(30);
  root->left->left->left = new node(10);
  root->left->left->left->left = new node(20);

  // 20 10 4 2 1 3 7 30 => op/7

  cout << "maxDiameter:" << diameterOfBinaryTree(root) << endl;
  return 0;
}