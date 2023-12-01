#include <iostream>
#include <locale>
#include <unordered_set>
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

// Method1: find loop in list using iteration
bool findloop(NODE head) {
  NODE slow, fast;
  slow = fast = head;
  while (slow && fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      return true;
  }
  return false;
}

// Method2: find loop in list in hash
bool findLoop_usingHash(NODE head){
    unordered_set<NODE> mySet;
    while (head != nullptr) {
        if (mySet.find(head) != mySet.end())
            return true;
        mySet.insert(head);
        head = head->next;
    }
    return false;
}

// find loop node in a list
NODE findloopNode(NODE head) {
  NODE slow, fast;
  slow = fast = head;
  while (slow && fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      break;
  }
  slow = head;
  while (slow != fast) {
    slow = slow->next;
    fast = fast->next;
  }
  return slow;
}

// remove loop from a list
void removeLoop(NODE head) {
  cout << "remove loop" << endl;
  NODE slow, fast;
  slow = fast = head;
  while (slow && fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
      break;
  }
  if (slow == fast) { // found loop
    slow = head;      // again start from begining
    while (slow->next != fast->next) {
      slow = slow->next;
      fast = fast->next;
    }
    fast->next = nullptr; // remove loop
  }
}

// count no of node in loop
int countNode(NODE start) {
  int cnt = 1;
  NODE tmp = start->next;
  while (start != tmp) {
    cout << "loop:" << tmp->data << endl;
    tmp = tmp->next;
    cnt++;
  }
  return cnt;
}
int countLoopNode(NODE head) {
  if (head == nullptr) {
    return 0;
  }
  NODE slow, fast;
  slow = fast = head;
  while (slow && fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      return countNode(slow);
    }
  }
  return 0;
}

// print list
void printlist(NODE head) {
  if (!head)
    return;
  cout << "data = " << head->data << endl;
  printlist(head->next);
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

  /*
    1   2    3   4   5   6   7
             |_______________|
  */
  printlist(head);
  // create loop in list 7th and 3rd
  head->next->next->next->next->next->next = head->next->next;
  if (findloop(head)) {
    if(findLoop_usingHash(head)){
      NODE loopNode = findloopNode(head);
      cout << "Found loop, loop node = " << loopNode->data << endl;
      cout << "loop node count:" << countLoopNode(head) << endl;
      removeLoop(head);
      printlist(head);
    }
  } else {
    cout << "no loop found" << endl;
    printlist(head);
  }
  return 0;
}