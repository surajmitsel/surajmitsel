#include <iostream>
using namespace std;

struct node {
  int data;
  struct node *link{nullptr};
  node(int data) : data(data) {}
};

struct node *reverse(struct node *root) {
  struct node *next = nullptr;
  struct node *new_root = nullptr;
  while (root) {
    next = root->link;
    root->link = new_root;
    new_root = root;
    root = next;
  }
  return new_root;
}

void printlist(struct node *root) {
  if (!root)
    return;
  cout << "list data:" << root->data << endl;
  printlist(root->link);
}

void deletelist(struct node *root) {
  if (!root) // root is null
    return;
  deletelist(root->link);
  cout << "deleting:" << root->data << endl;
  delete (root);
}

int main() {
  struct node *head = new node(3);
  head->link = new node(4);
  head->link->link = new node(5);
  head->link->link->link = new node(6);
  head->link->link->link->link = new node(7);

  head = reverse(head);

  printlist(head);
  deletelist(head);
  return 0;
}