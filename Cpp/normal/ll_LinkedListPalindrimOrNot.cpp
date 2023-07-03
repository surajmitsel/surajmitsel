#include <iostream>
#include <stack>
using namespace std;

struct node {
  int data;
  struct node *link{nullptr};
  node(int data) : data(data) {}
};

bool IsListPlindrom(struct node *root) {
  struct node *temp = root;
  stack<int> stk;
  while (temp) {
    stk.push(temp->data);
    temp = temp->link;
  }

  while (root) {
    if (root->data != stk.top()) {
      return false;
    }
    stk.pop();
    root = root->link;
  }
  return true;
}
int main() {
  struct node *root = new node(0);
  root->link = new node(1);
  root->link->link = new node(2);
  root->link->link->link = new node(3);
  root->link->link->link->link = new node(4);
  root->link->link->link->link->link = new node(3);
  root->link->link->link->link->link->link = new node(2);
  root->link->link->link->link->link->link->link = new node(1);
  root->link->link->link->link->link->link->link->link = new node(0);

  if (IsListPlindrom(root))
    cout << "List is palindrom";
  else
    cout << "List is not palindrom";
  return 0;
}