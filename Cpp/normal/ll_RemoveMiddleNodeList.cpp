#include <iostream>
#include <locale>
using namespace std;

struct node {
  int data;
  struct node *next{nullptr};
  node(int data) : data(data) {}
};
typedef struct node *NODE;

// insert node begining
void insert_front(NODE *head, int data) {
  NODE new_node = new node(data);
  new_node->next = *head;
  *head = new_node;
}

// insert node last
void insert_back(NODE *head, int data) {
  NODE new_node = new node(data);
  NODE temp = *head;
  if (*head == nullptr) {
    (*head) = new_node;
    return;
  }
  while (temp->next != nullptr) {
    temp = temp->next;
  }
  temp->next = new_node;
}

// print list
void printlist(NODE head) {
  if (!head)
    return;
  cout << "data = " << head->data << endl;
  printlist(head->next);
}

// Remove middle node if even then remove high node
void removeMiddleNode(NODE head) {
  NODE slow, fast, prevSlow;
  slow = fast = head;
  while (slow && fast && fast->next) {
    prevSlow = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  prevSlow->next = slow->next;
  cout << "removing node:" << slow->data << endl;
  delete slow;
}

int main() {
  struct node *head = nullptr;
  insert_back(&head, 1);
  insert_back(&head, 2);
  insert_back(&head, 3);
  insert_back(&head, 4);
  insert_back(&head, 5);
  insert_back(&head, 6);
  insert_back(&head, 7);
  insert_back(&head, 8);

  removeMiddleNode(head);

  printlist(head);
  return 0;
}