#include <iostream>
using namespace std;

struct node {
  int data;
  struct node *next{nullptr};
  node(int data) : data(data) {}
};

typedef struct node * NODE;


// Method1
NODE reverseList(NODE head) {
    NODE prev = nullptr;
    NODE current = head;
    NODE nextNode = nullptr;
    
    while (current != nullptr) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    
    return prev; // new head of the reversed list
}

// Method 2
NODE reverse(NODE root) {
  NODE next = nullptr;
  NODE new_root = nullptr;
  while (root) {
    next = root->next;
    root->next = new_root;
    new_root = root;
    root = next;
  }
  return new_root;
}

// Method 3
NODE reverseList_usingStack(NODE head) {
    if (head == nullptr || head->next == nullptr)
        return head;

    stack<NODE> s;
    NODE temp = head;

    // Push all elements onto the stack
    while (temp != nullptr) {
        s.push(temp);
        temp = temp->next;
    }

    // Create a new list by popping elements from the stack
    NODE newHead = s.top();
    s.pop();
    temp = newHead;

    while (!s.empty()) {
        temp->next = s.top();
        s.pop();
        temp = temp->next;
    }

    temp->next = nullptr; // Set the next of last node to nullptr

    return newHead;
}

void printlist(struct node *root) {
  if (!root)
    return;
  cout << "list data:" << root->data << endl;
  printlist(root->next);
}

void deletelist(struct node *root) {
  if (!root) // root is null
    return;
  deletelist(root->next);
  cout << "deleting:" << root->data << endl;
  delete (root);
}

int main() {
  struct node *head = new node(3);
  head->next = new node(4);
  head->next->next = new node(5);
  head->next->next->next = new node(6);
  head->next->next->next->next = new node(7);

  head = reverse(head);

  printlist(head);
  deletelist(head);
  return 0;
}