class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {

        queue<pair<int, int>> q;
        int count = 0;
        //q.push({stones[0][0], stones[0][1]});
        int size = stones.size();
        vector<int> vis(size, 0);
        //vis[0] = 1;
        for (int i = 0; i < size; i++) {
       
            if (!vis[i]) {
                vis[i] = 1;
                q.push({stones[i][0] , stones[i][1]});
                while (!q.empty()) {
                    auto it = q.front();
                    q.pop();

                    for (int i = 0; i < size; i++) {
                        if (!vis[i] && (stones[i][0] == it.first ||
                                        stones[i][1] == it.second)) {

                            count++;
                            q.push({stones[i][0], stones[i][1]});
                            vis[i] = 1;
                        }
                    }
                }
            }
        }

        return count;
    }
};
