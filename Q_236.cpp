/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        return dfs(root , p , q);
    }

    TreeNode* dfs(TreeNode* root , TreeNode* p , TreeNode* q){

        if(!root || root == p || root == q) return root;

        TreeNode* l = dfs(root->left , p , q);
        

        TreeNode* r = dfs(root->right , p , q);

        if(!l)return r;
        else if(!r) return l;
        else return root;

    }
};
