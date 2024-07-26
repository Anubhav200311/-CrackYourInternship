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
    bool isValidBST(TreeNode* root) {
        
        if(!root)return true;
        if(root->left && root->val <= maxvalue(root->left)) return false;
        if(root->right && root->val >= minvalue(root->right)) return false;
        if(!isValidBST(root->left) || !isValidBST(root->right)) return false;

        return true;
    }

    int minvalue(TreeNode* root){
        if(!root)return INT_MAX;

        int value = root->val;

        int l_min = minvalue(root->left);
        int r_min = minvalue(root->right);

        return min(value , min(l_min , r_min));
    }

    int maxvalue(TreeNode* root){
        if(!root) return INT_MIN;

        int value = root->val;
        int l_max = maxvalue(root->left);
        int r_max = maxvalue(root->right);

        return max(value , max(l_max , r_max));
    }
};
