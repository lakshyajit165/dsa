/*

Given the root node of a binary search tree (BST) and a value.
You need to find the node in the BST that the node's value equals the given value. 
Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.

For example, 

Given the tree:
        4
       / \
      2   7
     / \
    1   3

And the value to search: 2
You should return this subtree:

      2     
     / \   
    1   3
In the example above, if we want to search the value 5, 
since there is no node with value 5, we should return NULL.

Note that an empty tree is represented by NULL, 
therefore you would see the expected output (serialized tree format) as [], not null.


*/

#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
  
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if(root == NULL or root->val == val)
            return root;
        
        else if(val <= root->val)
            return searchBST(root->left, val);
        else 
            return searchBST(root->right, val);
       
    }

    // custom display function
    void display(TreeNode* res){
        if(!res)
            return;
        else{
            cout<<res->val<<" ";
            display(res->left);
            display(res->right);
        }
       
    }
};
int main() {

    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);

    Solution s;
    TreeNode* res = s.searchBST(root, 2);

    s.display(res);
    cout<<endl;
    return 0;
}