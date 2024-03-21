#include <iostream>
#include <queue>
using namespace std;

struct node {
  int data;
  struct node *left{nullptr};
  struct node *right{nullptr};
  // Constructor
  node(int data) : data(data) {}
};
typedef struct node *NODE;

void leftViewUntil(NODE root, int level, int *maxLevel) {
  if (root == nullptr)
    return;
  if (*maxLevel < level) {
    cout << root->data << endl;
    *maxLevel = level;
  }
  leftViewUntil(root->left, level + 1, maxLevel);  // first left
  leftViewUntil(root->right, level + 1, maxLevel); // then right
}

void rightViewUntil(NODE root, int level, int *maxLevel) {
  if (root == nullptr)
    return;
  if (*maxLevel < level) {
    cout << root->data << endl;
    *maxLevel = level;
  }
  rightViewUntil(root->right, level + 1, maxLevel); // first right
  rightViewUntil(root->left, level + 1, maxLevel);  // the left
}

void treeView(NODE root, string view) {
  std::cout << "tree view:" << view.c_str() << endl;

  int maxLevel = 0;
  if (view == "left")
    leftViewUntil(root, 1, &maxLevel);
  else if (view == "right")
    rightViewUntil(root, 1, &maxLevel);
}


//---------------------------------------------------------
void printLeftView(NODE root) {
    if (root == nullptr) return;

    queue<NODE> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();

        // Traverse all nodes at the current level
        for (int i = 1; i <= n; ++i) {
            NODE node = q.front();
            q.pop();

            // Print the leftmost node at each level
            if (i == 1) {
                cout << node->data << " ";
            }

            // Enqueue the left and right children of the current node
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
    }
}

void printRightView(NODE root) 
{
    if (root == nullptr) 
          return;
          
    queue<NODE> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();

        // Traverse all nodes at the current level
        for (int i = 1; i <= n; ++i) {
            NODE node = q.front();
            q.pop();

            // Print the leftmost node at each level
            if (i == 1) {
                cout << node->data << " ";
            }

            // Enqueue the right and then left children of the current node
            if (node->right != nullptr) {
                q.push(node->right);
            }
            if (node->left != nullptr) {
                q.push(node->left);
            }
        }
    }
}

int main() {
  struct node *root = new node(4);
  root->left = new node(5);
  root->right = new node(2);

  root->right->left = new node(3);
  root->right->right = new node(1);

  root->right->left->left = new node(6);
  root->right->left->right = new node(7);
  /*
              4
          5      2
              3     1
            6    7
  */
  treeView(root, "left");
  treeView(root, "right");

  std::cout << "left:"; printLeftView(root);
  std::cout << endl;
  std::cout << "right:"; printRightView(root);
}