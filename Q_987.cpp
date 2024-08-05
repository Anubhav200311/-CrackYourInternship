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
    vector<vector<int>> verticalTraversal(TreeNode* root) {

        queue<pair<TreeNode* ,pair <int , int>>> q;  // node {line , level}
        map<int, map<int , multiset<int>>> mp; // line level elements
        q.push({root,{0 , 0}});
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int line = it.second.first;
            int level = it.second.second;

            mp[line][level].insert(node->val);

            if (node->left)
                q.push({node->left , {line - 1 , level+1}});
            if (node->right)
                q.push({node->right , {line + 1 , level +1}});
        }

        vector<vector<int>>ans;

        for(auto it : mp){
            vector<int> layer;
            for(auto j : it.second){
                for(int i : j.second)layer.push_back(i);
            }
            ans.push_back(layer);
        }

        return ans;
    }
};
