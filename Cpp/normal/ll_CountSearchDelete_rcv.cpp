#include <cstring>
#include <iostream>
using namespace std;

struct node {
  int data;
  struct node *link{nullptr};
  node(int data) : data(data) {}
};

typedef struct node *NODE;

// recursive find
bool findElement(NODE head, int data) {
  if (head == nullptr)
    return false;
  if (head->data == data)
    return true;

  return findElement(head->link, data);
}

// recursive print
void printlist(NODE head) {
  if (!head)
    return;
  cout << "list data:" << head->data << endl;
  printlist(head->link);
}

// recursive count
int count(NODE head) {
  if (!head)
    return 0;
  return 1 + count(head->link);
}

// recursive delete
void deletelist(NODE head) {
  if (!head) // head is null
    return;
  deletelist(head->link);
  cout << "deleting:" << head->data << endl;
  delete (head);
}

int main() {
  NODE head = new node(3);
  head->link = new node(4);
  head->link->link = new node(5);
  head->link->link->link = new node(6);
  head->link->link->link->link = new node(7);
  head->link->link->link->link->link = new node(20);
  std::cout << "list count:" << count(head) << endl;
  printlist(head);
  std::cout << "findElement:" << findElement(head, 6) << endl;
  std::cout << "findElement:" << findElement(head, 10) << endl;
  deletelist(head);

  return 0;
}