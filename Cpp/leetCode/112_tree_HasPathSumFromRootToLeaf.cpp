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

bool HasPathSum(struct node* root, int targetSum) {
    if (!root)
        return false;
    
    targetSum = targetSum - root->data;
    if (root->left == nullptr && root->right == nullptr) // Check if leaf node
        return targetSum == 0;           // return true if tagetSum is reach to 0
    
    return HasPathSum(root->left, targetSum) || HasPathSum(root->right, targetSum);
}

int main(void) {
  /*
                  1
              2        3
            4   5    6    7
  */
  struct node *root = new node(1);
  root->left = new node(2);
  root->right = new node(3);
  root->left->left = new node(4);
  root->left->right = new node(5);
  root->right->left = new node(6);
  root->right->right = new node(7);

  cout << "HasPathSum:" << HasPathSum(root, 7) << endl;
  return 0;
}