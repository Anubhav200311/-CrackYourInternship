//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        vector<string>ans;
        string s = "";
        bfs(0 , 0 , s , ans , mat);
        return ans;
    }
    
    void bfs(int row , int col , string s , vector<string>& ans , vector<vector<int>> &mat){
        
        if(row < 0 || row > mat.size()-1 || col < 0  || col > mat[0].size()-1 || mat[row][col] == 0)
           return;
        
        if(row == mat.size()-1 && col == mat[0].size()-1){
            ans.push_back(s);
            return;
        }
        
        
        s = s + 'D';
        mat[row][col] = !mat[row][col];
        bfs(row+1 , col , s ,ans , mat);
        s.pop_back();
        //mat[row][col] = !mat[row][col];
        s = s + 'U';
        bfs(row-1 , col , s ,ans, mat);
        //mat[row][col] = !mat[row][col];
        s.pop_back();
        s = s + 'L';
        bfs(row , col-1 ,s ,ans, mat );
        s.pop_back();
        //mat[row][col] = !mat[row][col];
        s = s + 'R';
        bfs(row , col + 1 , s ,ans, mat);
        mat[row][col] = !mat[row][col];
        s.pop_back();
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
