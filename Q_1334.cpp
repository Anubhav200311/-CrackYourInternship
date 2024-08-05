class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n, vector<int>(n, INT_MAX));

        for (int i = 0; i < n; i++) {
            matrix[i][i] = 0;
        }

        formulateCost(n, edges, matrix);

        // Floyd-Warshall algorithm to find all-pairs shortest paths
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][k] != INT_MAX && matrix[k][j] != INT_MAX) {
                        matrix[i][j] =
                            min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                    }
                }
            }
        }

        int city = -1;
        int res = INT_MAX;

        for (int i = 0; i < n; i++) {
            int _value = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && matrix[i][j] <= distanceThreshold) {
                    _value++;
                }
            }
            if (_value <= res) {
                res = _value;
                city = i; 
                          // neighbors
            }
        }

        return city;
    }

    void formulateCost(int n, vector<vector<int>>& edges, vector<vector<int>>& matrix) {
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        int weight = edge[2];
        matrix[u][v] = weight;
        matrix[v][u] = weight;
    }
}
};
