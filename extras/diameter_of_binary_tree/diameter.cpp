/*

Diameter of Binary Tree
Solution
Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.




*/
#include<bits/stdc++.h>
using namespace std;

class TreeNode {

    public:     
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 
 };

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == NULL)
            return 0;
        
        int lheight = height(root->left);
        int rheight = height(root->right);
        
        int ldiameter = diameterOfBinaryTree(root->left);
        int rdiameter = diameterOfBinaryTree(root->right);
        
        return max(lheight+rheight, max(ldiameter, rdiameter));
    }
    
    int height(TreeNode* root){
        
        if(root == NULL)
            return 0;
        
        return 1 + max(height(root->left), height(root->right));
    }
};

int main() {
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);


     /* 
   
    Constructed binary tree is  
           1 
          / \ 
         2   3 
        / \ 
       4   5 
    
    */

    Solution s;

    cout<<s.diameterOfBinaryTree(root)<<endl;

    return 0;
}