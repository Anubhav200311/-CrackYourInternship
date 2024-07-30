class Solution {
    const int MOD = 1000000007;

public:
    int knightDialer(int n) {
        unordered_map<int, vector<int>> mp;

        mp[0] = {4, 6};
        mp[1] = {6, 8};
        mp[2] = {9, 7};
        mp[3] = {8, 4};
        mp[4] = {0, 3, 9};
        mp[6] = {7, 1, 0};
        mp[7] = {6, 2};
        mp[8] = {1, 3};
        mp[9] = {4, 2};

        vector<vector<int>> dp(10, vector<int>(n+1  , -1));
        int count = 0;
        for (int i = 0; i < 10; i++) {
            count = (count + fun(i, n, dp, mp)) % MOD;
        }

        return count;
    }

    int fun(int num, int n, vector<vector<int>>& dp,
            unordered_map<int, vector<int>>& mp){
                
                if(n == 1)return 1;
                if(dp[num][n] != -1)return dp[num][n];
                int sum = 0;
                for(int i : mp[num]){
                    sum = (sum + fun(i, n - 1, dp, mp)) % MOD;
                }

                return dp[num][n] = sum;
            }
};
