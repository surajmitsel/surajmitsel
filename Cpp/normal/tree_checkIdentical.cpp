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

bool identical_tree(NODE a, NODE b) {
  /*reached to empty element together*/
  if (a == nullptr && b == nullptr)
    return true;

  /*compare every element*/
  if (a != nullptr && b != nullptr) {
    return (a->data == b->data && identical_tree(a->left, b->left) &&
            identical_tree(a->right, b->right));
  }

  /*when one is reached to null but other is not*/
  return false;
}
int main() {
  cout << "hello" << std::endl;

  NODE root1 = newNode(1);
  root1->left = newNode(2);
  root1->right = newNode(3);
  root1->left->left = newNode(4);
  root1->left->right = newNode(5);

  NODE root2 = newNode(1);
  root2->left = newNode(2);
  root2->right = newNode(3);
  root2->left->left = newNode(4);
  root2->left->right = newNode(5);

  std::cout << "identical_tree:" << identical_tree(root1, root2);
  return 0;
}