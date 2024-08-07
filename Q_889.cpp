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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        
        int preindex = 0;
        int size = preorder.size();
        return helper(preorder , postorder , preindex , 0 , size - 1 , size);
    }

    TreeNode* helper(vector<int>& preorder , vector<int>& postorder , int& preindex , int low , int high , int size){

        if(preindex >= size || low > high)return nullptr;

        TreeNode* node = new TreeNode(preorder[preindex]);
        preindex++;

        if(low == high)return node;

        int i;
        for(int i = low ; i <= high ; i++){
            if(postorder[i] == preorder[preindex]) break;
        }

        if(i <= high){
            node->left = helper(preorder , postorder , preindex , low , i , size);

            node->right = helper(preorder , postorder , preindex , i + 1 , high -1, size);
        }

        return node;
        
    }
};
