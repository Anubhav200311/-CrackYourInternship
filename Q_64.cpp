class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return fun(0, 0, grid, dp, m, n);
    }

    int fun(int row, int col, vector<vector<int>>& grid,
            vector<vector<int>>& dp, int m, int n) {

        if (row == m - 1 && col == n - 1) {
            return grid[m - 1][n - 1];
        }
        if (dp[row][col] != -1)
            return dp[row][col];

        pair<int, int> adj[] = {{0, 1}, {1, 0}};

        int mini = INT_MAX;
        for (pair<int , int> i : adj) {
            int nrow = row + i.first;
            int ncol = col + i.second;

            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n) {
                mini = min(mini, grid[row][col] + fun(nrow, ncol, grid, dp, m, n));
            }
        }

        return dp[row][col] = mini;
    }
};
