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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        vector<TreeNode*> t;
        search(root, subRoot->val, t);
        for (TreeNode* it : t) {
            if (compare(it, subRoot))
                return true;
        }
        return false;
    }

    bool compare(TreeNode* root, TreeNode* subroot) {
        if (!root && subroot)
            return false;
        if (!subroot && root)
            return false;
        if (!root && !subroot)
            return true;
        if (root->val != subroot->val)
            return false;

        bool l_c = compare(root->left, subroot->left);
        if (!l_c)
            return false;
        bool r_c = compare(root->right, subroot->right);

        return r_c;

        return true;
    }

    void search(TreeNode* root, int val, vector<TreeNode*>& t) {

        if (!root)
            return;
        if (root->val == val)
            t.push_back(root);
        search(root->left, val, t);
        search(root->right, val, t);
    }
};
