/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {

        vector<string> s;
        string str = "";
        dfs(root, s, str);
        return s;
    }

    void dfs(TreeNode* root, vector<string>& s, string str) {

        if (!root)
            return;

        str += to_string(root->val);
        
        if (!root->left && !root->right) {
            s.push_back(str);
            return;
        }
        str += "->";
        if (root->left) {
            dfs(root->left, s, str);
        }
        if (root->right)
            dfs(root->right, s, str);
    }
};
