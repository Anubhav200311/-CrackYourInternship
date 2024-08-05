class Solution
{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node * bToDLL(Node *root)
    {
        // your code here
        Node* prev = NULL;
        Node* head = NULL;
        inorder(root , prev , head);
        return head;
    }
    void inorder(Node* root , Node*& prev , Node*& head){
        
        if(!root)return;
        
        inorder(root->left , prev , head);
        
        if(!head) head = root;
        
        if(prev){
          prev->right = root;
        }
        root->left = prev;
        prev = root;
        
        inorder(root->right ,  prev , head);
    }
};
