class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> counts(strs.size());
        for (int i = 0; i < strs.size(); ++i) {
            int count0 = count(strs[i].begin(), strs[i].end(), '0');
            int count1 = strs[i].size() - count0;
            counts[i] = {count0, count1};
        }

        //unordered_map<string, int> memo;
        vector<vector<vector<int>>> dp(strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));

        return fun(counts, 0, m, n, dp);
    }

    int fun(const vector<pair<int, int>>& counts, int index, int m, int n,
            vector<vector<vector<int>>>&dp) {
        if (index == counts.size())
            return 0;

        //string key = to_string(index) + "," + to_string(m) + "," + to_string(n);
        // if (memo.find(key) != memo.end())
        //     return memo[key];

        if(dp[index][m][n] != -1)return dp[index][m][n];

        int count0 = counts[index].first;
        int count1 = counts[index].second;

        int maxCount = fun(counts, index + 1, m, n, dp);

        if (m >= count0 && n >= count1) {
            maxCount = max(maxCount, 1 + fun(counts, index + 1, m - count0,
                                             n - count1, dp));
        }

        dp[index][m][n] = maxCount;
        return maxCount;
    }
};
