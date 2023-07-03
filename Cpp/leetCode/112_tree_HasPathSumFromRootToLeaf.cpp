#include <iostream>
#include <type_traits>

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

bool HasPathSum(NODE root, int target) {

  if (root == nullptr) // No node
    return 0;          // return value = 0;

  // only one node || last node in recursive call
  if (root->left == nullptr && root->right == nullptr)
    return (target == root->data); // return result

  bool result = false;
  // seperate if not if-else
  if (root->left)
    result = HasPathSum(root->left, (target - root->data));

  if (root->right)
    result = result || HasPathSum(root->right, (target - root->data));

  return result;
}

int main(void) {
  /*
                   1
              2         3
            4   5     6    7
  */

  struct node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right->left = new node(6);
  root->right->right = new node(7);

  cout << "HasPathSum:" << HasPathSum(root, 8) << endl;
  return 0;
}