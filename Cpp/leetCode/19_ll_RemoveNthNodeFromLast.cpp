#include <iostream>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
    if(!head){
        return nullptr;
    }
    ListNode* first = head;
    ListNode * nth = head;
    ListNode * prev;
    int count = 0;

    while(nth->next){
        count ++;
        if(count == n){
            break;
        }
        nth = nth->next;
    }
    cout << count;
    if(count != n || nth->next == nullptr){
        return nullptr;
    }
    
    while (nth->next != nullptr){
        prev = first;
        nth = nth->next;
        first = first->next;
    }
    prev->next = first->next;
    delete(first);
    return head;
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    ListNode* tmp = removeNthFromEnd(head,4);
    while(tmp){
        cout << tmp->val << ",";
        tmp = tmp->next;
    }
    return 0;
}