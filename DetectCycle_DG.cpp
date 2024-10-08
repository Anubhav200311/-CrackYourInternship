//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V , 0);
        vector<int>p_vis(V , 0);
        for(int i  = 0 ; i < V ; i++){
            if(!vis[i]){
                if(dfs(i , vis , p_vis , adj)) return true;
            }
        }
        
        return false;
    }
    
    bool dfs(int node , vector<int>& vis , vector<int>& p_vis , vector<int>adj[]){
        
        vis[node] = 1;
        p_vis[node] = 1;
        for(int i : adj[node]){
            if(!vis[i]){
                if(dfs(i , vis , p_vis , adj)) return true;
            }else if(p_vis[i])return true;
        }
        p_vis[node] = 0;
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends
