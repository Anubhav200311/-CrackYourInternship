//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
   
    int findDist(Node* root, int a, int b) {
        if (!root) return -1;

        unordered_map<Node*, Node*> parentMap;
        parentMap[root] = nullptr;
        Node* nodeA = nullptr;

        formulateParents(root, nullptr, parentMap, a, nodeA);

        if (!nodeA) return -1;

        queue<Node*> q;
        q.push(nodeA);
        unordered_map<Node*, bool> visited;
        visited[nodeA] = true;

        int distance = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node* node = q.front();
                q.pop();

                if (node->data == b) return distance;

                if (node->left && !visited[node->left]) {
                    visited[node->left] = true;
                    q.push(node->left);
                }
                if (node->right && !visited[node->right]) {
                    visited[node->right] = true;
                    q.push(node->right);
                }
                if (parentMap[node] && !visited[parentMap[node]]) {
                    visited[parentMap[node]] = true;
                    q.push(parentMap[node]);
                }
            }
            distance++;
        }

        return -1; 
    }

private:
    void formulateParents(Node* root, Node* parent, unordered_map<Node*, Node*>& parentMap, int a, Node*& nodeA) {
        if (!root) return;

        parentMap[root] = parent;

        if (root->data == a) nodeA = root;

        formulateParents(root->left, root, parentMap, a, nodeA);
        formulateParents(root->right, root, parentMap, a, nodeA);
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends
