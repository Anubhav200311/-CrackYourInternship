class Solution {
public:
    // Directions for knight moves
    vector<pair<int, int>> directions = {
        {1, -2}, {1, 2}, {-1, -2}, {-1, 2},
        {-2, -1}, {-2, 1}, {2, -1}, {2, 1}
    };

    int minStepToReachTarget(vector<int>& KnightPos, vector<int>& TargetPos, int N) {
        if (KnightPos == TargetPos) return 0;

        vector<vector<bool>> vis(N + 1, vector<bool>(N + 1, false));

        queue<pair<int, int>> q;

        q.push(make_pair(KnightPos[0], KnightPos[1]));
        vis[KnightPos[0]][KnightPos[1]] = true;

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                pair<int, int> current = q.front();
                int current_row = current.first;
                int current_col = current.second;
                q.pop();

                if (current_row == TargetPos[0] && current_col == TargetPos[1]) {
                    return steps;
                }

                for (size_t j = 0; j < directions.size(); ++j) {
                    int new_row = current_row + directions[j].first;
                    int new_col = current_col + directions[j].second;

                    if (new_row > 0 && new_row <= N && new_col > 0 && new_col <= N && !vis[new_row][new_col]) {
                        vis[new_row][new_col] = true;
                        q.push(make_pair(new_row, new_col));
                    }
                }
            }
            ++steps;
        }

        return -1;
    }
};


