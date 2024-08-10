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
class BSTIterator {
public:
   BSTIterator(TreeNode* root) {
        pushLeftmostNodes(root);
    }
    
    int next() {
        TreeNode* node = nodesStack.top();
        nodesStack.pop();
        
        if (node->right != nullptr) {
            pushLeftmostNodes(node->right);
        }
        
        return node->val;
    }
    
    bool hasNext() {
        return !nodesStack.empty();
    }
    private:
    stack<TreeNode*> nodesStack;

    void pushLeftmostNodes(TreeNode* node) {
        while (node != nullptr) {
            nodesStack.push(node);
            node = node->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */     
