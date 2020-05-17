/*

Given a singly linked list, group all odd nodes together followed by the even nodes.
 Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place.
 The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
Note:

The relative order inside both the even and odd groups should
 remain as it was in the input.

The first node is considered odd, the second node even and so on ...

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
    ListNode* oddEvenList(ListNode* head) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if(!head or !head->next)
            return head;

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* Ehead = head->next;

        while(even and even->next){

            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;

        }

        odd->next = Ehead;
        return head;

    }
};
int main() {

    ListNode* head = NULL;
    ListNode* start = NULL;
    int ele;
    
    while ((cin.peek() != '\n') && (cin.peek() != EOF)) {
        cin>>ele;

        ListNode* new_node = new ListNode(ele);
        // new_node->val = ele;
        new_node->next = NULL;

        if(head == NULL){
            head = new_node;
            start = head;
        }
        else
        {   
            start->next = new_node;
            start = new_node;
        }
    }

    Solution s;

    ListNode* oddeven = s.oddEvenList(head);
    start = oddeven;

    while(start != NULL){
        cout<<start->val<<" ";
        start = start->next;
    }

    return 0;
}