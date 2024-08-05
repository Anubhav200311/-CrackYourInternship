class Solution {
public:
     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        int originalColor = image[sr][sc];

        if (originalColor == color) return image;

        queue<pair<int, int>> q;
        q.push({sr, sc});

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        while (!q.empty()) {
            pair<int, int> it = q.front();
            q.pop();

            image[it.first][it.second] = color;

            for (pair<int, int> dir : directions) {
                int nrow = it.first + dir.first;
                int ncol = it.second + dir.second;

                if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && image[nrow][ncol] == originalColor) {
                    q.push({nrow, ncol});
                }
            }
        }

        return image;
    }

};
