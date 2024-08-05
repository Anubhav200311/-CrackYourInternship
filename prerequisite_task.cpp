//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool dfs(int node, vector<vector<int>>& adj, vector<int>& visited, vector<int>& recStack) {
    visited[node] = 1;
    recStack[node] = 1;

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, visited, recStack)) {
                return true;
            }
        } else if (recStack[neighbor]) {
            return true; 
        }
    }

    recStack[node] = 0; 
    return false;
}

bool isPossible(int N, int P, vector<pair<int, int>>& prerequisites) {
    vector<vector<int>> adj(N);

    for (const auto& pre : prerequisites) {
        int u = pre.first;
        int v = pre.second;
        adj[u].push_back(v);
    }

    vector<int> visited(N, 0);
    vector<int> recStack(N, 0);

    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack)) {
                return false; 
            }
        }
    }

    return true; 
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends
