#include <bits/stdc++.h> 
using namespace std; 
  
/* A binary tree node has data, pointer to 
   left child and a pointer to right child */
class Node 
{ 
    public:  
      int data; 
      Node *left, *right; 
    
      Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
      }
}; 
  
/* Returns true if the given 
tree is a BST and its values 
are >= min and <= max. */
int isBSTUtil(Node* node, int min, int max)  
{  
    /* an empty tree is BST */
    if (node==NULL)  
        return 1;  
              
    /* false if this node violates 
    the min/max constraint */
    if (node->data < min || node->data > max)  
        return 0;  
      
    /* otherwise check the subtrees recursively,  
    tightening the min or max constraint */
    return
        isBSTUtil(node->left, min, node->data-1) && // Allow only distinct values  
        isBSTUtil(node->right, node->data+1, max); // Allow only distinct values  
}  
  
  
int isBST(Node* node)  
{  
    return(isBSTUtil(node, INT_MIN, INT_MAX));  
}  
  
  
/* Driver program to test above functions*/
int main() 
{ 
    Node* root = new Node(5); 
    root->left = new Node(2); 
    root->right = new Node(6); 
    root->left->left = new Node(1); 
    root->left->right = new Node(4); 
  
    if (isBST(root)) 
        cout << "Is BST"; 
    else
        cout << "Not a BST"; 
  
    return 0; 
} 