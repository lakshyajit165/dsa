/*

Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos
 which represents the position (0-indexed) in the linked list where tail connects to. 
 If pos is -1, then there is no cycle in the linked list.

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the second node.

Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the first node.


LOGIC----

maintain 2 pointers, one slow pointer to be incremented one at a time and another fast pointer to be incremented 2 steps at a time.
They will be equal at some point if there is a cycle in the linked list.

*/

#include<bits/stdc++.h>
using namespace std;
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
     
        ListNode* slow = head;
        
        if(head == NULL or head->next == NULL)
            return false;
        
        ListNode* fast = head->next;
        
        while(slow != fast){
            if(fast == NULL or fast->next == NULL)
                return false;
            
            slow = slow->next;
            fast = fast->next->next;
            
        }
        
        return true;
    }
};