/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };

 You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists in a one sorted list. The list should be made by splicing
together the nodes of the first two lists.

Return the head of the merged linked list.
Example 1:


Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]

 */
#include <iostream>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
// METHOD1
ListNode *mergeTwoShortedLists_1(ListNode *list1, ListNode *list2) {

  if (list1 == nullptr)
    return list2;
  if (list2 == nullptr)
    return list1;

  if (list1->val < list2->val) {
    list1->next = mergeTwoShortedLists_1(list1->next, list2);
    return list1;
  } else {
    list2->next = mergeTwoShortedLists_1(list1, list2->next);
    return list2;
  }
}

// METHOD2
ListNode* mergeTwoLists_2(ListNode* l1, ListNode* l2) {
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = (l1) ? l1 : l2;

    ListNode* head = dummy->next;
    delete dummy; // Prevent memory leak
    return head;
}

int main() {
  ListNode *list1 = new ListNode(3);
  list1->next = new ListNode(4);
  list1->next->next = new ListNode(7);
  list1->next->next->next = new ListNode(9);

  ListNode *list2 = new ListNode(1);
  list2->next = new ListNode(2);
  list2->next->next = new ListNode(8);

  // ListNode *list_m1 = mergeTwoShortedLists_1(list1, list2);
  // while (list_m1) {
  //   std::cout << list_m1->val << ",";
  //   list_m1 = list_m1->next;
  // }

  ListNode *list_m2 = mergeTwoLists_2(list1, list2);
  while (list_m2) {
    std::cout << list_m2->val << ",";
    list_m2 = list_m2->next;
  }



}
