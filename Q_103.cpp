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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(!root) return ans;

        queue<TreeNode*>q;
        q.push(root);
        bool left_to_right = true;
        while(!q.empty()){
            
            int level_size = q.size();
            vector<int>temp(level_size);

            for(int i = 0 ; i < level_size ; i++){

                int index = left_to_right?i:level_size - i - 1;
                TreeNode* t = q.front();
                q.pop();
                temp[index] = t->val;
                if(t->left)q.push(t->left);
                if(t->right)q.push(t->right);
            }
            ans.push_back(temp);
            left_to_right = !left_to_right;
        }

        return ans;
    }
};
