class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {

        queue<pair<int, int>> q;
        int n = grid.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j])
                    q.push({i, j});
            }
        }
        if (q.size() == 0 || q.size() == n * n) {
        return -1;
    }
        int res = -1;
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!q.empty()) {

            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            res = grid[r][c];

            for (auto it : dir) {
                int nrow = r + it.first;
                int ncol = c + it.second;
                if (min(nrow, ncol) >= 0 && max(nrow, ncol) < n &&
                    grid[nrow][ncol] == 0) {
                    q.push({nrow, ncol});
                    grid[nrow][ncol] = 1 + grid[r][c];
                }
            }
        }

        
        return res - 1;
    }
};
