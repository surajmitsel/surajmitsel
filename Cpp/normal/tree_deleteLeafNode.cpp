#include <cstring>
#include <iostream>
#include <type_traits>
using namespace std;

struct node {
  int data;
  struct node *left{nullptr};
  struct node *right{nullptr};
  // constructor
  node(int data) : data(data) {}
};

// get new node
struct node *newNode(int data) {
  return new node(data);
}
typedef struct node *NODE;

NODE deleteLeafNode(NODE root, int delVal) {
  if (root == nullptr)
    return nullptr;
  root->left = deleteLeafNode(root->left, delVal);
  root->right = deleteLeafNode(root->right, delVal);
  // found node
  if (delVal == root->data && root->left == nullptr && root->right == nullptr) {
    cout << "deleting:" << root->data << endl;
    delete (root);
    return nullptr;
  }
  return root;
}
void inorder(NODE root) {
  if (!root)
    return;
  inorder(root->left);
  cout << "data:" << root->data << endl;
  inorder(root->right);
}
int main() {
  cout << "hello" << std::endl;

  NODE root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  inorder(root);
  root = deleteLeafNode(root, 5);
  inorder(root);
  return 0;
}