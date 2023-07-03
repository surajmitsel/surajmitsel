#include <iostream>
#include <stack>
#include <unordered_set>

using namespace std;

struct node {
  int data;
  struct node *next{nullptr};
  node(int data) : data(data) {}
};
typedef struct node *NODE;
//---------------------------------------------

void printlist(NODE head) {
  if (!head)
    return;
  cout << "list data:" << head->data << endl;
  printlist(head->next);
}

void deletelist(NODE head) {
  if (!head) // root is null
    return;
  deletelist(head->next);
  cout << "deleting:" << head->data << endl;
  delete (head);
}

// METHOD1: interactive
void ConcatenateList_itr(NODE head1, NODE head2) {
  if (head1 && head2) { // both are not null
    while (head1->next) {
      head1 = head1->next;
    }
    head1->next = head2; // append the list2 into list1
  }
}
// METHOD2: recursive
void ConcatenateList_rcv(NODE head1, NODE head2) {
  if (head1 && head2) { // both are not null
    if (head1->next == nullptr) {
      head1->next = head2;
    } else {
      ConcatenateList_rcv(head1->next, head2);
    }
    // append the list2 into list1
  }
}

int main() {
  NODE head1 = new node(1);
  head1->next = new node(2);
  head1->next->next = new node(3);
  head1->next->next->next = new node(4);
  head1->next->next->next->next = new node(5);
  head1->next->next->next->next->next = new node(6);

  NODE head2 = new node(20);
  head2->next = new node(30);
  head2->next->next = new node(40);
  head2->next->next->next = new node(50);
  head2->next->next->next->next = new node(60);
  head2->next->next->next->next->next = new node(70);

  NODE head3 = new node(200);
  head3->next = new node(300);
  head3->next->next = new node(400);
  head3->next->next->next = new node(500);
  head3->next->next->next->next = new node(600);
  head3->next->next->next->next->next = new node(700);

  std::cout << "ConcatenateList_rcv" << endl;
  ConcatenateList_rcv(head1, head2); // head1 = head1+head2+head2
  printlist(head1);

  cout << "ConcatenateList_itr" << endl;
  ConcatenateList_itr(head1, head3); // head1 = head1+head2
  printlist(head1);

  return 0;
}