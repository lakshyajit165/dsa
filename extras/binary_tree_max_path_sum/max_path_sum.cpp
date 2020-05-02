/*


Given a non-empty binary tree, find the maximum path sum.

For this problem, a path is defined as any sequence of nodes 
from some starting node to any node in the tree along the parent-child connections.
The path must contain at least one node and does not need to go through the root.

Example 1:

Input: [1,2,3]

       1
      / \
     2   3

Output: 6
Example 2:

Input: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

Output: 42







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
    int maxpathsum_util(TreeNode *root, int &result){
        
        if(!root)
            return 0;
        
        int left = maxpathsum_util(root->left, result);
        int right = maxpathsum_util(root->right, result);
        
        int max_straight = max(max(left, right) + root->val, root->val);
        int max_case_val = max(max_straight, left + right + root->val);
        
        result = max(max_case_val, result);
        
        return max_straight;
        
    }
    int maxPathSum(TreeNode* root) {
        
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int result = INT_MIN;
        maxpathsum_util(root, result);
        
        return result;
    }
};
int main() {

    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution s;

    cout<<s.maxPathSum(root)<<endl;
    return 0;
}