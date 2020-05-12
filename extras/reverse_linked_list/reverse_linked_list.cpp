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
    ListNode* reverseList(ListNode* head) {
        
//         1-> 2-> 3-> 4-> 5
        
//         pre = NULL
//         next = NULL
//         curr = 1
        
//         nt = curr->next;
//         curr->next = pre
//         pre = curr
//         curr = nt
    
        // ListNode* temp = head;
        
        
        ListNode* pre = NULL;
        ListNode* curr = head;
        ListNode* nt = NULL;
    
        
        while(curr != NULL){
            nt = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nt;
        }
    
        
        return pre;
           
        
          
    }
};

int main() {

    ListNode* head = new ListNode(1);
    ListNode* t = head;

    int count = 2;
    while(count <= 5){
        ListNode* temp = new ListNode(count);
        t->next = temp;
        t = t->next;
        count++;
    }

    Solution s;
    ListNode* st = s.reverseList(head);

    while(st != nullptr){
        cout<<st->val<<"->";
        st = st->next;
    }
    return 0;
}