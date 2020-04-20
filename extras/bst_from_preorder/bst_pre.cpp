/*


Construct Binary Search Tree from Preorder Traversal
Solution
Return the root node of a binary search tree that matches the given preorder traversal.

(Recall that a binary search tree is a binary tree where for every node,
 any descendant of node.left has a value < node.val, and any descendant of 
 node.right has a value > node.val.  Also recall that a preorder traversal 
 displays the value of the node first, then traverses node.left, then traverses node.right.)

 

Example 1:

Input: [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

 

Note: 

1 <= preorder.length <= 100
The values of preorder are distinct.


*/


#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {

public:
    queue<int> q;

    TreeNode* BstInsert(TreeNode*& root, int val){
        if(!root){    
            root = new TreeNode(val);

            //
            q.push(val);
        }else{  
            if(val < root->val)  {
                root->left  = BstInsert(root->left, val); 
                
                //
                q.push(val);    
            }  
            else if(root->val < val) {
                root->right = BstInsert(root->right, val);
                q.push(val);   
            }
        }
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        TreeNode* root = NULL;
        
        for (auto val : preorder)
            BstInsert(root, val);
        
        return root;
    }

    void printBst(TreeNode* root){

        list<TreeNode*> queue;
        queue.push_back(root);

        TreeNode* curr = NULL;

        while(queue.size()){

            curr = queue.front();
            queue.pop_front();

            cout<<curr->val<<" ";

            if(curr->left)
                queue.push_back(curr->left);
            
            if(curr->right)
                queue.push_back(curr->right);
           
        }
    }

   
};

int main() {

    vector<int> preorder;
    int ele;

    while(cin.peek() != '\n' and cin.peek() != EOF){
        cin>>ele;
        preorder.push_back(ele);
    }

    Solution s;

    TreeNode* root = s.bstFromPreorder(preorder);

    s.printBst(root);
    

    return 0;

}