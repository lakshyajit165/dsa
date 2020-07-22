/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?

LOGIC:

1. Maintain two pointers first and second
2. Increment the second pointer till the nth node from the beginning.
3. Now keep on incrementing both the pointers till the second pointer is at the last node.
4. after above steps the first pointer will be pointing to the nth node from the beginning.
5. delete the node which the first pointer is pointing to.

*/
#include<bits/stdc++.h>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(head->next == NULL)
            return NULL;
        
        
        ListNode* first = head;
        ListNode* second = head;
        
        int count = 1;
        
        
        while(count != n){
            second = second->next;
            count++;
        }
        
        if(second->next == NULL)
            return head->next;
        
        // cout<<second->val<<" "<<endl;
        
        while(second->next->next){
            first = first->next;
            second = second->next;
            
            
        }
       
        
        first->next = first->next->next;
        return head; 
        
        
       
    }
};

int main() {

    return 0;
}