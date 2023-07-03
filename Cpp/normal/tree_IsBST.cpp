#include <array>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std;
struct node {
  int data;
  struct node *right{nullptr};
  struct node *left{nullptr};
  node(int data) : data(data) {}
};
typedef struct node *NODE;

//---------------METHODE1---------------------------
void inorder_vec(NODE root, vector<int> &vec) {
  if (root == nullptr)
    return;
  inorder_vec(root->left, vec);
  cout << root->data;
  vec.push_back(root->data);
  inorder_vec(root->right, vec);
}

bool isBst_usingVec(NODE root) {
  vector<int> vec;
  inorder_vec(root, vec);
  cout << endl;
  for (auto x : vec) {
    cout << "vec:" << x << ",";
  }
  for (vector<int>::iterator it = vec.begin(); it != (vec.end() - 1); it++) {
    if (*it >= *(it + 1))
      return false;
  }
  return true;
}
//---------------METHODE2---------------------------
bool inorder_prevNode(NODE root, NODE &prev) {
  if (!root) {
    return true; // till last node
  }
  if (false == inorder_prevNode(root->left, prev)) {
    return false;
  }
  if (prev && prev->data > root->data) {
    return false;
  }
  prev = root;
  return inorder_prevNode(root->right, prev);
}
bool isBst_usingPrevNode(NODE root) {
  NODE prev = nullptr;
  return inorder_prevNode(root, prev);
}

int main() {

  //            4
  //         2     5
  //       1   3

  struct node *root = new node(4);
  root->left = new node(2);
  root->right = new node(5);
  root->left->left = new node(1);
  root->left->right = new node(3);
  cout << endl;
  // Method1
  if (isBst_usingVec(root)) {
    cout << endl << "its BST" << std ::endl;
  } else {
    cout << endl << "not bst" << std ::endl;
  }

  // Method2
  if (isBst_usingPrevNode(root)) {
    cout << endl << "its BST" << std ::endl;
  } else {
    cout << endl << "not bst" << std ::endl;
  }
  return 0;
}
