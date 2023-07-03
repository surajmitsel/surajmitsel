#include <iostream>
#include <stack>
using namespace std;

struct node {
  int data;
  struct node *link{nullptr};
  node(int data) : data(data) {}
};
typedef struct node *NODE;
//---------------------------------------------
// METHOD1 by treversion two times to list
bool isPalindrom(NODE head) {
  stack<int> stk;
  NODE tmp = head;
  while (tmp) {
    stk.push(tmp->data);
    tmp = tmp->link;
  }
  while (head) {
    if (head->data != stk.top())
      return false;
    stk.pop();
    head = head->link;
  }
  return true;
}
//---------------------------------------------
// METHOD2 by treversion only once to list
bool isPalindrom_opt(NODE head) {
  std::stack<int> stk;
  NODE slow = head;
  NODE fast = head;
  // just only traverse half of the list
  while (slow && fast && fast->link) {
    stk.push(slow->data);
    slow = slow->link;
    fast = fast->link->link;
  }

  if (fast == nullptr) {
    // even number of node in list
  } else if (fast->link == nullptr) {
    // odd  number of node in list
    slow = slow->link;
  }

  // compare half of the list with half filled stack
  while (slow) {
    if (slow->data != stk.top())
      return false;
    stk.pop();
    slow = slow->link;
  }
  return true;
}
//---------------------------------------------
// METHOD3 by recursive
bool isPalindrom_rcv(NODE *left, NODE right) {
  if (right == nullptr) {
    return true;
  }
  bool result =
      isPalindrom_rcv(left, right->link) && ((*left)->data == right->data);
  (*left) = (*left)->link;

  // OR enble this block and comment previous lines
  // bool result = isPalindrom_rcv(left, right->link);
  // if ((*left)->data == right->data) {
  //   (*left) = (*left)->link;
  // } else {
  //   result = false;
  // }

  return result;
}

void printlist(struct node *head) {
  if (!head)
    return;
  cout << "list data:" << head->data << endl;
  printlist(head->link);
}

void deletelist(struct node *head) {
  if (!head) // root is null
    return;
  deletelist(head->link);
  cout << "deleting:" << head->data << endl;
  delete (head);
}

int main() {
  struct node *head = new node(1);
  head->link = new node(2);
  head->link->link = new node(3);
  head->link->link->link = new node(3);
  head->link->link->link->link = new node(2);
  head->link->link->link->link->link = new node(1);
  printlist(head);
  cout << "isPalindrom:" << isPalindrom(head) << endl;
  cout << "isPalindrom_opt:" << isPalindrom_opt(head) << endl;
  cout << "isPalindrom_rcv:" << isPalindrom_rcv(&head, head) << endl;
  deletelist(head);

  head = new node(1);
  head->link = new node(2);
  head->link->link = new node(3);
  head->link->link->link = new node(2);
  head->link->link->link->link = new node(1);
  printlist(head);
  cout << "isPalindrom:" << isPalindrom(head) << endl;
  cout << "isPalindrom_opt:" << isPalindrom_opt(head) << endl;
  cout << "isPalindrom_rcv:" << isPalindrom_rcv(&head, head) << endl;
  deletelist(head);
  return 0;
}