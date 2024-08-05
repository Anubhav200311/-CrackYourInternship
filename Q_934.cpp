class Solution {
public:
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // Direction vectors

bool invalid(int row, int col, int n) {
    return row < 0 || col < 0 || row >= n || col >= n;
}

void dfs(vector<vector<int>>& grid, set<pair<int, int>>& vis, int row, int col, int n) {
    if (invalid(row, col, n) || grid[row][col] != 1 || vis.find({row, col}) != vis.end())
        return;

    vis.insert({row, col});
    for (pair<int, int> d : dir) {
        dfs(grid, vis, row + d.first, col + d.second, n);
    }
}

int bfs(vector<vector<int>>& grid, set<pair<int, int>>& vis, int n) {
    queue<pair<int, int>> q;
    for (pair<int, int> i : vis) {
        q.push(i);
    }

    int res = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (pair<int, int> it : dir) {
                int nrow = row + it.first;
                int ncol = col + it.second;

                if (invalid(nrow, ncol, n) || vis.find({nrow, ncol}) != vis.end())
                    continue;

                if (grid[nrow][ncol] == 1)
                    return res; // Found the shortest path to the second island

                q.push({nrow, ncol});
                vis.insert({nrow, ncol});
            }
        }
        res += 1;
    }
    return res;
}

int shortestBridge(vector<vector<int>>& grid) {
    set<pair<int, int>> vis;
    int n = grid.size();

    // Find the first island and mark all its cells
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (found) break;
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1) {
                dfs(grid, vis, i, j, n);
                found = true;
                break;
            }
        }
    }

    // Use BFS to find the shortest bridge to the second island
    return bfs(grid, vis, n);
}
};
