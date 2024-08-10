/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        
        return helper(root->left , 1) + helper(root->right , 0);
    }

    int helper(TreeNode* root , int flag){

        if(!root)return 0;
        if(!root->left && !root->right && flag)return root->val;

        return helper(root->left , 1) + helper(root->right , 0);
    }
};
