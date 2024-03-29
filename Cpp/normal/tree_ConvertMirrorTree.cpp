#include <iostream>
#include <type_traits>

using namespace std;
struct node {
  int data;
  struct node *left{nullptr};
  struct node *right{nullptr};
  // Constructor
  node(int data) : data(data) {}
};

void inorder(struct node *root) {
  if (!root)
    return;
  inorder(root->left);
  cout << root->data << ",";
  inorder(root->right);
}

void mirror(struct node *root) {
  if (!root)
    return;

  mirror(root->left);
  mirror(root->right);
  struct node *temp;
  temp = root->left;
  root->left = root->right;
  root->right = temp;
}

int main(void) {
  struct node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);


  /*        1                1
          2   3   =>      3     2
        4  5                  5   4
  */


  inorder(root);  // 4,2,5,1,3,
  mirror(root);
  cout << std::endl;
  inorder(root);  // 3,1,5,2,4,
  return 0;
}