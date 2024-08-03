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
    void flatten(TreeNode* root) {
        
        TreeNode* res = nullptr;

        pre(root , res);
        
    }
    void pre(TreeNode* root , TreeNode*& res){

        if(!root)return;

        TreeNode* rightsub_tree = root->right;
        
        if(res){
            res->right = root;
            res->left = nullptr;
        }
        res = root;
        pre(root->left , res);
        pre(rightsub_tree , res);
    }
};
