/*

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

To represent a cycle in the given linked list, 
we use an integer pos which represents the position (0-indexed) in the linked list 
where tail connects to. If pos is -1, then there is no cycle in the linked list.

Note: Do not modify the linked list.


Input: head = [3,2,0,-4], pos = 1
Output: tail connects to node index 1
Explanation: There is a cycle in the linked list, where tail connects to the second node.


Input: head = [1,2], pos = 0
Output: tail connects to node index 0
Explanation: There is a cycle in the linked list, where tail connects to the first node.


Input: head = [1], pos = -1
Output: no cycle
Explanation: There is no cycle in the linked list.



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
    ListNode *detectCycle(ListNode *head) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
     
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* ans = NULL;
        bool flag = false; //initially assume there isn't any cycle

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){
                flag = true;
                break;
            }
        }
        fast = head;
        if(flag){ // if there is a cycle
            while(1){
                if(fast==slow){ 
                    ans = fast; 
                    break; 
                }// the origin of the cycle}
                fast =fast->next; slow = slow->next;
            }
        }
        return ans;
        }     
        
    
};