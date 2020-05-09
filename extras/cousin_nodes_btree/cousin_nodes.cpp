/*

In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.



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
    int find_HeightParent(TreeNode *curr, int &parent, int value, int height){
        
        if(!curr)
            return 0;
        
        if(curr->val == value)
            return height;
        
        parent = curr->val;
        int left = find_HeightParent(curr->left, parent, value, height+1);
        if(left)
            return left;
        
        parent = curr->val;
        int right = find_HeightParent(curr->right, parent, value, height+1);
        return right;
    }
public:
    bool isCousins(TreeNode* root, int x, int y) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        if(root->val == x || root->val == y)
            return false;
        
        int xParent = -1;
        int xHeight = find_HeightParent(root, xParent, x, 0);
        
        int yParent = -1;
        int yHeight = find_HeightParent(root, yParent, y, 0);
        
        if(xParent != yParent and xHeight == yHeight)
            return true;
        return false;
    }
};

int main() {

    TreeNode* node = new TreeNode(1);
    
    node->left = new TreeNode(2);
    node->right = new TreeNode(3);

    node->left->left = nullptr;
    node->left->right = new TreeNode(4);

    node->right->left = nullptr;
    node->right->right = new TreeNode(5);

    

    Solution s;
    cout<<s.isCousins(node, 5, 4)<<endl;

    return 0;
}