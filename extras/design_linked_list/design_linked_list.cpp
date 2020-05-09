/*


Design your implementation of the linked list. You can choose to use the 
singly linked list or the doubly linked list. A node in a singly linked list 
should have two attributes: val and next. val is the value of the current
 node, and next is a pointer/reference to the next node. If you want to
  use the doubly linked list, you will need one more attribute prev to 
  indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement these functions in your linked list class:

get(index) : Get the value of the index-th node in the linked list. If the index is invalid, return -1.

addAtHead(val) : Add a node of value val before the first element of the linked list. 
After the insertion, the new node will be the first node of the linked list.

addAtTail(val) : Append a node of value val to the last element of the linked list.

addAtIndex(index, val) : Add a node of value val before the index-th node in the linked list.
 If index equals to the length of linked list, the node will be appended to 
 the end of linked list. If index is greater than the length, the node will not be inserted.
 
deleteAtIndex(index) : Delete the index-th node in the linked list, if the index is valid.
 

Example:

Input: 
["MyLinkedList","addAtHead","addAtTail","addAtIndex","get","deleteAtIndex","get"]
[[],[1],[3],[1,2],[1],[1],[1]]
Output:  
[null,null,null,null,2,null,3]

Explanation:
MyLinkedList linkedList = new MyLinkedList(); // Initialize empty LinkedList
linkedList.addAtHead(1);
linkedList.addAtTail(3);
linkedList.addAtIndex(1, 2);  // linked list becomes 1->2->3
linkedList.get(1);            // returns 2
linkedList.deleteAtIndex(1);  // now the linked list is 1->3
linkedList.get(1);            // returns 3
 

Constraints:

0 <= index,val <= 1000
Please do not use the built-in LinkedList library.
At most 2000 calls will be made to get, addAtHead, addAtTail,  addAtIndex and deleteAtIndex


*/


#include<bits/stdc++.h>
using namespace std;
class Node {
    
    public:
        int val;
        Node* next;
        Node(int x){
            val = x;
            next = NULL;
        }
        
};

class MyLinkedList {
public:
    /** Initialize your data structure here. */
    Node* head;
    Node* tail;
    
    int size;
    
    MyLinkedList() {
        this->head = NULL;
        this->tail = NULL;
        this->size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        
        if(index > size or index < 0) return -1;
        
        int count = 0;
        Node* temp = this->head;
        
        while(temp){
            if(count++ == index)
                return temp->val;
            temp = temp->next;
                
        }
        
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        
        Node* newnode = new Node(val);
        
        if(this->head == NULL){
            this->head = newnode;
            this->tail = newnode;
        }else{
            newnode->next = this->head;
            this->head = newnode;
        }
        this->size++;
        
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        
        Node* newnode = new Node(val);
        
        if(this->head == NULL){
            this->head = newnode;
            this->tail = newnode;
        }else{
            this->tail->next = newnode;
            this->tail = newnode;
        }
        this->size++;
        
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        
        Node* newnode = new Node(val);
        
        if(index > this->size) return;
        
        
        
        if(index == this->size){
            this->addAtTail(val);
            return;
        }
        
        if(index == 0){
            this->addAtHead(val);
            return;
        }
        
        int count = 0;
        Node* temp = this->head;
        
        while(temp){
            if(count++ == index-1){
                newnode->next = temp->next;
                temp->next = newnode;
                break;
            }
            temp = temp->next;
        }
        
        this->size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        
        if (index >= this->size) return;
        if (index == 0) {
            this->head = this->head->next;            
        }
        else {
            int ct = 0;
            Node *tmp = this->head;
            for (int i = 0; i< index -1; i++)
                tmp = tmp->next;
            tmp->next = tmp->next->next;
            if (index == this->size-1) {
                this->tail = tmp;
            }
            
        }
        this->size--;
    }

    // My own function
    void display(){

        Node* temp = this->head;
        while(temp){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"null";
    }
};

int main(){

    MyLinkedList* obj = new MyLinkedList();
    int param_1 = obj->get(1);
    cout<<param_1<<endl;
    
    obj->addAtHead(1);
    obj->addAtTail(2);

    obj->display();

    cout<<endl;

    obj->addAtIndex(1,3);

    obj->display();

    cout<<endl;

    obj->deleteAtIndex(2);

    obj->display();

    return 0;
}