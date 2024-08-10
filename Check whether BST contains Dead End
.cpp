class Solution{
  public:
    bool isDeadEnd(Node *root)
    {
        //Your code here
        return dfs(root , 1, INT_MAX);
    }
    bool dfs(Node* root , int low , int high){
        
        if(!root)return false;
        
        if(low == high) return true;        
        return dfs(root->left , low , root->data-1) || dfs(root->right , root->data+1 , high);
        
        
    }
};

