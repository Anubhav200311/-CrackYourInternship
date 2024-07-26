vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V , 0);
        vector<int>ans;
        dfs(0 , adj , vis , ans);
        return ans;
    }
    
    void dfs(int node , vector<int>adj[] , vector<int>& vis , vector<int>& ans){
        
        vis[node] = 1;
        ans.push_back(node);
        
        for(int i : adj[node]){
            
            if(!vis[i]) dfs(i , adj , vis , ans);
        }
        
    }
