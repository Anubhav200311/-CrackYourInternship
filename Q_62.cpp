class Solution {
public:
    int uniquePaths(int m, int n) {
        
        vector<vector<int>>dp(m , vector<int>(n , -1));
        int count = 0;
        return fun(m-1 , n-1 , dp , count);
    }

    int fun(int m , int n ,vector<vector<int>>& dp , int &count){
        
        if(m == 0 && n == 0){
            count++;
            return 1;
        }
        if(dp[m][n] != -1)return dp[m][n];
        int up = 0 ;
        int left = 0;
        if(m -1 >= 0)up=fun(m-1 , n ,dp , count);
        if(n-1 >= 0)left=fun(m , n-1 , dp , count);

        return dp[m][n] = up + left;
    }
};
