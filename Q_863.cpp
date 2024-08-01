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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        map<TreeNode*, TreeNode*> mp;

        mp[root] = NULL;
        map<TreeNode*, bool> vis;
        formulateParents(root, mp);

        queue<TreeNode*> q;
        q.push(target);

        vis[target] = true;
        int dist = 0;
        while (!q.empty()) {

            int size = q.size();

            if (dist == k)
                break;

            dist++;
            for (int i = 0; i < size; i++) {
                TreeNode* t = q.front();
                q.pop();

                if (t->left && !vis[t->left]) {
                    q.push(t->left);
                    vis[t->left] = true;
                }
                if (t->right && !vis[t->right]) {
                    q.push(t->right);
                    vis[t->right] = true;
                }
                if (mp[t] && !vis[mp[t]]) {
                    q.push(mp[t]);
                    vis[mp[t]] = true;
                }
            }
        }

        vector<int> result;
        while (!q.empty()) {
            result.push_back(q.front()->val);
            q.pop();
        }

        return result;
    }

    void formulateParents(TreeNode* root, map<TreeNode*, TreeNode*>& mp) {

        queue<TreeNode*> q;
        q.push(root);
        // vis[root] = false;
        while (!q.empty()) {

            TreeNode* t = q.front();
            q.pop();
            // vis[t] = false;
            if (t->left) {
                q.push(t->left);
                mp[t->left] = t;
            }
            if (t->right) {
                q.push(t->right);
                mp[t->right] = t;
            }
        }
    }
};
