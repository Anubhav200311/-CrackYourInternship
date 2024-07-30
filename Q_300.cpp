class Solution {
public:
    int fun(int index, int prev_index, vector<int>& arr, int n,
            vector<vector<int>>& dp) {
        if (index == n)
            return 0;
        if (dp[index][prev_index + 1] != -1)
            return dp[index][prev_index + 1];

        int len = fun(index + 1, prev_index, arr, n, dp);

        if (prev_index == -1 || arr[index] > arr[prev_index]) {
            len = max(len, 1 + fun(index + 1, index, arr, n, dp));
        }

        return dp[index][prev_index + 1] = len;
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return fun(0, -1, nums, n, dp);
    }
};
