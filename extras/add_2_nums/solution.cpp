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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int carry = 0;
        ListNode* res = new ListNode();
        ListNode* start = res;
        
        while(l1 or l2){
            
            ListNode* temp;
            
            if(l1 and l2){
                
                int value = (l1->val + l2->val + carry) % 10;
                
                carry = (l1->val + l2->val + carry) / 10; 
                
                temp = new ListNode(value);
                
                l1 = l1->next;
                l2 = l2->next;
                
            }else if(l1) {
                
                temp = new ListNode((l1->val + carry) % 10);
                
                carry = (l1->val + carry) / 10;
                
                l1 = l1->next;
                
            }else{
                
                temp = new ListNode((l2->val + carry) % 10);
                
                carry = (l2->val + carry) / 10;
                
                l2 = l2->next;
                
            }
            res->next = temp;
            res = temp;
            
        
        }
        
        // if carry != 0. one more node to be added;
        if(carry){
            ListNode* temp = new ListNode(carry);
            res->next = temp;
        }
        return start->next;
    }
};
int main() {
    return 0;
}