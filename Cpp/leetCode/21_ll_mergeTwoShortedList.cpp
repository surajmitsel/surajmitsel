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

ListNode *mergeTwoShortedLists(ListNode *list1, ListNode *list2) {

  if (list1 == nullptr)
    return list2;
  if (list2 == nullptr)
    return list1;

  if (list1->val < list2->val) {
    list1->next = mergeTwoShortedLists(list1->next, list2);
    return list1;
  } else {
    list2->next = mergeTwoShortedLists(list1, list2->next);
    return list2;
  }
}

int main() {
  ListNode *list1 = new ListNode(5);
  list1->next = new ListNode(6);
  list1->next->next = new ListNode(7);

  ListNode *list2 = new ListNode(1);
  list2->next = new ListNode(2);
  list2->next->next = new ListNode(4);

  ListNode *list = mergeTwoShortedLists(list1, list2);
  while (list) {
    std::cout << list->val << ",";
    list = list->next;
  }
}
