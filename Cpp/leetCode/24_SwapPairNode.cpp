#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

ListNode* swapPairs_1(ListNode* head) 
{
    if(!head){
        return nullptr;
    }
    ListNode * dummy = new ListNode(0);
    dummy->next = head;

    ListNode * point = dummy;

    while(point->next != nullptr && point->next->next != nullptr){
        ListNode* swap1 =  point->next;
        ListNode* swap2 =  point->next->next;

        // Swapping nodes
        point->next = swap2;
        swap1->next = swap2->next;
        swap2->next = swap1;

        // Move to the next pair
        point = swap1;
    }
    return dummy->next;  
}

ListNode* swapPairs_rec(ListNode* head) {
    // Base case: If the list is empty or has only one node, return head
    if (!head || !head->next) {
        return head;
    }
    
    // Swap the first two nodes
    ListNode* newHead = head->next;
    head->next = swapPairs_rec(newHead->next);
    newHead->next = head;
    
    // Return the new head of the swapped list
    return newHead;
}
int main(){
    // 1 2 3 4 5
    ListNode* h1 = new ListNode(1);
    h1->next = new ListNode(2);
    h1->next->next = new ListNode(3);
    h1->next->next->next = new ListNode(4);
    h1->next->next->next->next = new ListNode(5);
    //ListNode* h2 = swapPairs_1(h1);
    // 
    // while(h2){
    //     cout << h2->val << ",";
    //     h2 =h2->next;
    // }
    // cout << endl;

    ListNode* h2 = swapPairs_rec(h1);
    // 1 2 3 4 5
    while(h2){
        cout << h2->val << ",";
        h2 = h2->next;
    }
    cout << endl; // 2,1,4,3,5,

    return 0;
}