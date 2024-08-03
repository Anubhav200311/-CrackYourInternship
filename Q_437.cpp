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
    int pathSum(TreeNode* root, int targetSum) {
        
        if(!root)return 0;
        
        int pathFromRoot = dfs(root , targetSum);
        
        int pathOnLeft = pathSum(root->left , targetSum);

        int pathOnRight = pathSum(root->right , targetSum);

        return pathFromRoot + pathOnLeft + pathOnRight;
    }

    int dfs(TreeNode* root , long long targetSum){

        if(!root)return 0;
        int count = 0;
        if(root->val == targetSum) count++;

        count += dfs(root->left , targetSum - root->val);
        count += dfs(root->right , targetSum - root->val);

        return count;
    }
};
