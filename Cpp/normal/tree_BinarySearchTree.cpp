#include <iostream>
#include <type_traits>
using namespace std;

struct node {
  int data;
  struct node *left{nullptr};
  struct node *right{nullptr};
  node(int data) : data(data) {}
};

void inorder(struct node *root) {
  if (!root)
    return;
  inorder(root->left);
  cout << root->data << ",";
  inorder(root->right);
}

void preorder(struct node *root) {
  if (!root)
    return;
  cout << root->data << ",";
  preorder(root->left);
  preorder(root->right);
}

void postorder(struct node *root) {
  if (!root)
    return;
  postorder(root->left);
  postorder(root->right);
  cout << root->data << ",";
}

struct node *insert(struct node *root, int key) {
  if (!root)
    return new node(key);

  if (key > root->data)
    root->right = insert(root->right, key);
  else if (key < root->data)
    root->left = insert(root->left, key);

  return root;
}

void deleteTree(struct node *root) {
  if (!root)
    return;

  deleteTree(root->left);
  cout << "deleting..." << root->data << endl;
  deleteTree(root->right);

  delete (root);
}

struct node *findMinValNode(struct node *root) {
  struct node *current = root;
  while (current != nullptr & current->left != nullptr) {
    current = current->left;
  }
  return current;
}

struct node *findMaxValNode(struct node *root) {
  struct node *current = root;
  while (current != nullptr & current->right != nullptr) {
    current = current->right;
  }
  return current;
}

struct node *deleteNode(struct node *root, int key) {
  if (!root)
    return root;

  if (key < root->data)
    root->left = deleteNode(root->left, key);
  else if (key > root->data)
    root->right = deleteNode(root->right, key);
  else { // this is the node which needs to be deleted

    if (root->left == nullptr) {
      struct node *temp = root->right;
      delete (root);
      return temp;
    } else if (root->right == nullptr) {
      struct node *temp = root->left;
      delete (root);
      return temp;
    } else {
      struct node *temp = findMinValNode(root->right);
      root->data = temp->data;
      root->right = deleteNode(root->right, temp->data);
    }
  }
  return root;
}

struct node *findnode(struct node *root, int key) {
  if (key > root->data)
    return findnode(root->right, key);
  else if (key < root->data)
    return findnode(root->left, key);
  else
    return root;
}

int main() {
  struct node *root = nullptr;
  root = insert(root, 10);
  insert(root, 50);
  insert(root, 30);
  insert(root, 60);
  insert(root, 20);
  insert(root, 40);
  insert(root, 80);
  insert(root, 70);
  insert(root, 100);
  insert(root, 90);

  preorder(root);
  cout << endl;

  inorder(root);
  cout << endl;

  postorder(root);
  cout << endl;

  deleteNode(root, 40);
  inorder(root);

  struct node *x = findMinValNode(root);
  cout << "min val " << x->data << endl;

  x = findMaxValNode(root);
  cout << "max val " << x->data << endl;

  x = findnode(root, 30);

  struct node *y = x->left;
  cout << "data " << y->data << endl;

  deleteTree(root);
  return 0;
}