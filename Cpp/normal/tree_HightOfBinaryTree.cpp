#include <iostream>
using namespace std;
struct node {
  int data;
  struct node *left{nullptr};
  struct node *right{nullptr};
  // Constructor
  node(int data) : data(data) {}
};
//method1
int hight(struct node * root) {
  if (!root)
    return 0;
  return 1 + std::fmax(hight(root->left), hight(root->right));
}
//method2
int hightOfTree(struct node *root) {
  if (!root)
    return 0;

  int lhight = hightOfTree(root->left);
  int rhight = hightOfTree(root->right);

  if (lhight > rhight)
    return lhight + 1;
  else
    return rhight + 1;
}

int main() {
  struct node *root = new node(1); // @level 1
  root->left = new node(2);        // @level 2
  root->right = new node(3);       // @level 2

  root->left->left = new node(4);   //@level 3
  root->right->right = new node(5); //@level 3

  root->right->right->right = new node(6);               // @level 4
  root->right->right->right->right = new node(7);        // @level 5
  root->right->right->right->right->right = new node(8); // @level 6

  root->left->left->left = new node(9);                    // @level 4
  root->left->left->left->left = new node(10);             // @level 5
  root->left->left->left->left->left = new node(11);       // @level 6
  root->left->left->left->left->left->left = new node(12); // @level 7

  cout << "Hight of Tree " << hightOfTree(root) << endl;
  cout << "Hight of Tree " << hight(root) << endl;
}