class Solution {
public:
    int numDecodings(string s) {

        vector<int> dp(s.size(), -1);
        return dfs(s, 0, dp);
    }
    int dfs(string s, int index, vector<int>& dp) {
        if (index == s.length())
            return 1;

        if (s[index] == '0')
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int res = dfs(s, index + 1, dp);

        if (index + 1 < s.length() &&
            (s[index] == '1' || s[index] == '2' && s[index + 1] <= '6'))
            res += dfs(s, index + 2, dp);

        return dp[index] = res;
    }
};
