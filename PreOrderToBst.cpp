class Solution {
  public:
    // Function that constructs BST from its preorder traversal.
    Node* Bst(int pre[], int size) {
        // code here
        if(size == 0)return NULL;
        Node* root = newNode(pre[0]);
        
        int index = 1;
        fun(pre , index , size , INT_MIN , root->data , root);
        fun(pre , index , size , root->data , INT_MAX , root);
        
        return root;
    }
    
    void fun(int pre[] , int& index , int size , int low , int high , Node* parent){
        
        if(index >= size)return;
        
        if(pre[index] > low && pre[index] < high){
            Node* temp = newNode(pre[index]);
            
            if(pre[index] > parent->data){
                parent->right = temp;
                parent = parent->right;
            }else{
                parent->left = temp;
                parent = parent->left;
            }
            
            index++;
            fun(pre , index , size , low , temp->data , temp);
            fun(pre , index , size , temp->data , high , temp);
        }
        
       
    }
