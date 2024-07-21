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
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;

        merge(root1, root2);
        return root1;
    }

private:
    void merge(TreeNode* root1, TreeNode* root2) {
        if (!root1 || !root2) return;

        root1->val += root2->val;

        if (root1->left && root2->left) {
            merge(root1->left, root2->left);
        } 
        else if (!root1->left && root2->left) {
            root1->left = new TreeNode(root2->left->val);
            copySubTree(root1->left, root2->left);
        }

        if (root1->right && root2->right) {
            merge(root1->right, root2->right);
        }
        else if (!root1->right && root2->right) {
            root1->right = new TreeNode(root2->right->val);
            copySubTree(root1->right, root2->right);
        }
    }

    void copySubTree(TreeNode* root1, TreeNode* root2) {
        if (!root2) return;
        if (root2->left) {
            root1->left = new TreeNode(root2->left->val);
            copySubTree(root1->left, root2->left);
        }
        if (root2->right) {
            root1->right = new TreeNode(root2->right->val);
            copySubTree(root1->right, root2->right);
        }
    }
};
