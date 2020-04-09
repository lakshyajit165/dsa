#include<bits/stdc++.h>
using namespace std;

class Node { 
public: 
    int val; 
    Node* next; 
}; 

// 
class Solution {
public:

    // function assumes size of linked list is NOT passed to it

    Node* middleNode(Node* head) {
        
        int cnt = 0;
        Node* start = head;
        
        while(start != NULL){
            cnt += 1;
            start = start->next;
        }
        
        int mid = cnt / 2 + 1;
        
        
        cnt = 0;
        start = head;
        
        while(cnt != mid-1) {
            
            start = start->next;
            cnt += 1;
        }

        return start;

    }
};

int main() {

    int n;
    cin>>n;

    int ele;

    Node* head = NULL;
    Node* start = NULL;

    for(int i = 0; i<n; i++){
        cin>>ele;

        Node* new_node = new Node();
        new_node->val = ele;
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
    
    // -------------------Prints the input Linked List -------------------------

    // start = head;

    // while (start != NULL) { 
    //     cout << start->val << " "; 
    //     start = start->next; 
    // } 

    // -------------------Print from the middle part of linked list -----------------------
    
    start = head;
    Solution s;
    Node* mid = s.middleNode(start);

    while(mid != NULL){
        cout<<mid->val<<" ";
        mid = mid->next;
    } 

    return 0;
}