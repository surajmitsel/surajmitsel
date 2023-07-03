#include <iostream>
#include <stack>
#include <unordered_set>

using namespace std;

struct node {
  int data;
  struct node *link{nullptr};
  node(int data) : data(data) {}
};
typedef struct node *NODE;
//---------------------------------------------

void printlist(NODE head) {
  if (!head)
    return;
  cout << "list data:" << head->data << endl;
  printlist(head->link);
}

void deletelist(NODE head) {
  if (!head) // root is null
    return;
  deletelist(head->link);
  cout << "deleting:" << head->data << endl;
  delete (head);
}

int CountCommonInTwoList(NODE head1, NODE head2) {
  int count = 0;
  unordered_set<int> mySet{0};
  while (head1) {
    mySet.insert(head1->data);
    head1 = head1->link;
  }
  while (head2) {
    if (mySet.find(head2->data) != mySet.end()) {
      count++;
    }
    head2 = head2->link;
  }
  return count;
}

int main() {
  NODE head1 = new node(1);
  head1->link = new node(2);
  head1->link->link = new node(3);
  head1->link->link->link = new node(4);
  head1->link->link->link->link = new node(5);
  head1->link->link->link->link->link = new node(6);

  NODE head2 = new node(2);
  head2->link = new node(3);
  head2->link->link = new node(3);
  head2->link->link->link = new node(5);
  head2->link->link->link->link = new node(6);
  head2->link->link->link->link->link = new node(2);
  cout << "common node count:" << CountCommonInTwoList(head1, head2) << endl;

  return 0;
}