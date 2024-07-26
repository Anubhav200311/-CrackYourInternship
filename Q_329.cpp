class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();
        int path_length = 1;
        vector<vector<int>>dp(m , vector<int>(n , -1));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                path_length = max(bfs(i, j, matrix, 1 , m, n , dp) , path_length );
            }
        }

        return path_length;
    }

    int bfs(int row, int col, vector<vector<int>>& matrix, int count , int m , int n , vector<vector<int>>&dp) {

       
       if(dp[row][col] != -1)return dp[row][col];
        pair<int, int> dir[] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
        int ma_x = count;
        for (pair i : dir) {
            int nrow = row + i.first;
            int ncol = col + i.second;
            if (nrow >= 0 && nrow < m && ncol >= 0 &&
                ncol < n){
                    if(matrix[nrow][ncol] > matrix[row][col]){
                        ma_x = max(ma_x ,count+ bfs(nrow , ncol , matrix , count , m , n , dp));
                    }
                }
        }

        return dp[row][col] = ma_x;
    }
};
