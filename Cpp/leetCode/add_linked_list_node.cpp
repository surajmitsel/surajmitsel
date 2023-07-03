
#include <iostream>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

  int carry = 0;
  ListNode *temp = nullptr;
  ListNode *head = temp;
  while ((l1 != nullptr) && (l2 != nullptr)) {
    int val = carry + l1->val + l2->val;
    if (temp != nullptr) {
      temp->next = new ListNode(val % 10);
      temp = temp->next;
    } else {
      temp = new ListNode(val % 10);
      head = temp;
    }
    carry = val / 10;
    l1 = l1->next;
    l2 = l2->next;
  }

  while (l1 != nullptr) {
    int val = carry + l1->val;
    if (temp) {
      temp->next = new ListNode(val % 10);
      temp = temp->next;
    } else {
      temp = new ListNode(val % 10);
      head = temp;
    }
    carry = val / 10;
    l1 = l1->next;
  }

  while (l2 != nullptr) {
    int val = carry + l2->val;
    if (temp) {
      temp->next = new ListNode(val % 10);
      temp = temp->next;
    } else {
      temp = new ListNode(val % 10);
      head = temp;
    }
    carry = val / 10;
    l2 = l2->next;
  }
  while (carry) {
    temp->next = new ListNode(carry % 10);
    carry = carry / 10;
  }

  return head;
}

int main() {

  // 971
  struct ListNode *list1 = new ListNode(1);
  list1->next = new ListNode(7);
  list1->next->next = new ListNode(9);

  // 715
  struct ListNode *list2 = new ListNode(5);
  list2->next = new ListNode(1);
  list2->next->next = new ListNode(7);
  // 1686
  struct ListNode *result = addTwoNumbers(list1, list2);
  cout << "add node value = ";
  while (result != nullptr) {
    cout << result->val << "";
    result = result->next;
  }
  std::cout << endl;
}