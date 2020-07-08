#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        if (root == NULL)
            return 0;
        else
            return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main()
{

    return 0;
}