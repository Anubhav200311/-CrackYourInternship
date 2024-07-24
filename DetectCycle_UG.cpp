//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<int>vis(V , 0);
        vector<int>p_vis(V , 0);
        
        for(int i = 0 ; i < V ; i++){
            
            if(!vis[i]){
                
                if(detect(i ,-1, vis , p_vis , adj)) return true;
            }
        }
        
        
        return false;
    }
    
    bool detect(int node , int parent , vector<int>& vis , vector<int>& p_vis , vector<int>adj[]){
        
        vis[node] = 1;
        p_vis[node] = 1;
        
        
        for(int i : adj[node]){
            
            
            if(i != parent){
                
                if(!vis[i]){
                    if(detect(i , node , vis , p_vis , adj)) return true;
                }
                else if(p_vis[i])return true;
            }
        }
        
        p_vis[node] = 0;
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends
