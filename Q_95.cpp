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
    vector<TreeNode*> generateTrees(int n) {
    
        return generate(1 , n);
        
    }

    vector<TreeNode*> generate(int left , int right){

        vector<TreeNode*>res;

        if(left > right){
            res.push_back(nullptr);
            return res;
        }

        for(int i = left ; i < right + 1 ; i++){
            for(TreeNode* j : generate(left , i-1 )){
                for(TreeNode* k : generate(i+1 , right)){
                    TreeNode* t = new TreeNode(i , j , k);
                    res.push_back(t);
                }
            }
        }
        return res;
    }
};
