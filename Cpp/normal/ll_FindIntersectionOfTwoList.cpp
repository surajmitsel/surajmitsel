#include <cstddef>
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

// METHOD1: using hash --------------------------
NODE findIntersection_hash(NODE head1, NODE head2) {
  unordered_set<NODE> mySet;
  while (head1) {
    mySet.insert(head1);
    head1 = head1->next;
  }
  while (head2) {
    if (mySet.find(head2) != mySet.end()) { // found
      return head2;
    } else {
      head2 = head2->next;
    }
  }
  return nullptr;
}

// METHOD2: using Difference --------------------------
int getListCount(NODE head) {
  if (!head) {
    return 0;
  }
  return 1 + getListCount(head->next);
}
NODE _intersecion(int diff, NODE head1, NODE head2) {
  while(diff){
    head1 = head1->next;
    diff--;
  }
  
  while (head1 && head2) {
    if (head1 == head2)
      return head1;
    head1 = head1->next;
    head2 = head2->next;
  }
  return nullptr;
}
NODE findIntersection_diff(NODE head1, NODE head2) {
  if (!head1 || !head2) return nullptr;

  int length1 = getListCount(head1);
  int length2 = getListCount(head2);
  if (length1 > length2) {
    return _intersecion(length1 - length2, head1, head2);
  }
  return _intersecion(length2 - length1, head2, head1);
}

// METHOD3: using without diff ---------
NODE findIntersection_withoutDiff(NODE head1, NODE head2) {
    if (!head1 || !head2) return nullptr;
    
    int len1 = 0, len2 = 0;
    // Calculate the lengths of both lists
    len1 = getListCount(head1);
    len2 = getListCount(head2);

    // Reset the pointers
    NODE tempA = head1;
    NODE tempB = head2;

    // Traverse the longer list to align starting points
    while (len1 > len2) {
        tempA = tempA->next;
        len1--;
    }
    while (len2 > len1) {
        tempB = tempB->next;
        len2--;
    }

    // Traverse both lists together until an intersection is found
    while (tempA && tempB) {
        if (tempA == tempB) 
            return tempA;
        tempA = tempA->next;
        tempB = tempB->next;
    }

    // If no intersection is found
    return nullptr;
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
  head2->next->next->next->next = head1->next->next;
  /*
        1->2->3->4->5->6
                 ^
                 |
    20->30->40->50

  */
  std::cout << "list1--------" << endl;
  printlist(head1);
  std::cout << "list2--------" << endl;
  printlist(head2);
  NODE find;
  if ((find = findIntersection_hash(head1, head2)) != nullptr) {
    std::cout << "findIntersection_hash:" << find->data << endl;
  } else {
    cout << "findIntersection_hash:not found" << endl;
  }

  if ((find = findIntersection_diff(head1, head2)) != nullptr) {
    std::cout << "findIntersection_diff:" << find->data << endl;
  } else {
    cout << "findIntersection_diff:not found" << endl;
  }


  if ((find = findIntersection_withoutDiff(head1, head2)) != nullptr) {
    std::cout << "findIntersection_withoutDiff:" << find->data << endl;
  } else {
    cout << "findIntersection_withoutDiff:not found" << endl;
  }

  return 0;
}