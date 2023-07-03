// Type your code here, or load an example.
#include <cmath>
#include <cstdint>
#include <iostream>
#include <string.h>

class test {
  test(test &) {}
};
struct node {
  int value;
  struct node *left{nullptr};
  struct node *right{nullptr};
};
typedef struct node *NODE;

NODE get_node(int val) {
  NODE temp = new struct node;
  temp->value = val;
  return temp;
}

NODE insert_node(NODE root, int val) {
  if (!root)
    return get_node(val);
  if (val < root->value)
    root->left = insert_node(root->left, val);
  else
    root->right = insert_node(root->right, val);
  return root;
}

NODE FindMinValueNode(NODE root) {
  NODE current = root;
  while (current && current->left)
    current = current->left;
  return current;
}
void pre_order(NODE root) {
  if (!root)
    return;
  else {
    pre_order(root->left);
    std::cout << root->value << ",";
    pre_order(root->right);
  }
}
int height(NODE root) {
  if (root == nullptr)
    return 0;
  return 1 + std::fmax(height(root->left), height(root->right));
}
int main() {
  NODE root = nullptr;
  root = insert_node(root, 5);
  insert_node(root, 14);
  insert_node(root, 3);
  insert_node(root, 2);
  insert_node(root, 1);
  insert_node(root, 0);
  insert_node(root, 9);
  insert_node(root, 4);
  insert_node(root, -1);

  pre_order(root);

  std::cout << FindMinValueNode(root)->value << std::endl;
  std::cout << "height:" << height(root) << std::endl;
  return 0;
}
