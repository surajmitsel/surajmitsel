#include <iostream>
using namespace std;

struct node {
  int data;
  struct node *next{nullptr};
  node(int data) : data(data) {}
};
typedef struct node *NODE;

// Method1: using one pointer
NODE deleteDuplicates(NODE head) {
  NODE current = head;
  while (current && current->next) {
      if (current->val == current->next->val) {
          NODE temp = current->next;
          current->next = current->next->next;
          delete temp;
      } else {
          current = current->next;
      }
  }
  return head;
}

// Method2: using 2 pointer
void removeDuplicate(NODE root) {
  std::cout << "removeDuplicate:" << endl;
  if (root == nullptr || root->next == nullptr) {
    // if no or only one node
    return;
  }
  NODE curr = root;
  NODE next_Node = root->next;
  while (next_Node != nullptr) {
    if (curr->data == next_Node->data) {
      NODE temp = next_Node;
      next_Node = next_Node->next;
      curr->next = next_Node;
      delete temp;
    } else {
      curr = curr->next;
      next_Node = next_Node->next;
    }
  }
}

void printlist(NODE root) {
  if (!root)
    return;
  cout << "list data:" << root->data << endl;
  printlist(root->next);
}

void deletelist(NODE root) {
  if (!root) // root is null
    return;
  deletelist(root->next);
  cout << "deleting:" << root->data << endl;
  delete (root);
}

int main() {
  NODE head = new node(1);
  head->next = new node(5);
  head->next->next = new node(5);
  head->next->next->next = new node(7);
  head->next->next->next->next = new node(7);
  head->next->next->next->next->next = new node(8);

  removeDuplicate(head);

  printlist(head);
  deletelist(head);
  return 0;
}