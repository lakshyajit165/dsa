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
    TreeNode* BstInsert(TreeNode*& root, int val){
        if(!root){    
            root = new TreeNode(val);
        }else{  
            if(val < root->val)  
                root->left  = BstInsert(root->left, val);   
            else if(root->val < val)  
                root->right = BstInsert(root->right, val);
        }
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        TreeNode* root = NULL;
        
        for (auto val : preorder)
            BstInsert(root, val);
        
        return root;
    }


};
int main() {

    vector<int> preorder{8,5,1,7,10,12};

    Solution s;

    TreeNode* res = s.bstFromPreorder(preorder);
    
    // display the resultant tree
    return 0;
}