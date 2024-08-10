class Solution{
public:
    int getCount(Node *root, int l, int h)
    {
      // your code goes here  
    //   if(l > root->data)return getCount(root->right , l , h);
    //   if(h < root->data)return getCount(root->left , l , h);
      
      return count(root , l , h);
      
    }
    
    int count(Node* root , int l , int h){
        if(!root)return 0;
        
        int c = 0;
        if(root->data >= l && root->data <= h )c = 1;
        
        return count(root->left , l , h) + count(root->right , l , h) + c;
    }
};

