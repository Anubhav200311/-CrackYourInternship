class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        inorder(root , pre , suc , key);
    }
    
    void inorder(Node* root , Node* &pre , Node*&suc , int key){
        
        if(!root)return;
        
        inorder(root->left , pre , suc , key);
        
        if(root->key < key)pre = root;
        if(!suc && root->key > key){
            suc = root;
            return;
        }
        inorder(root->right , pre , suc , key );
    }
};
