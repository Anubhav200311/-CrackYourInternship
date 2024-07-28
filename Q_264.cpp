class Solution {
public:
    int nthUglyNumber(int n) {
        
        vector<int>dp(n);
        dp[0] = 1;
        int p1 = 0;
        int p2 = 0;
        int p3 = 0;

        for(int i = 1; i < n ; i++){
              
            int two_m = dp[p1] * 2;
            int three_m = dp[p2] * 3;
            int five_m = dp[p3] * 5 ;

            dp[i] = min(two_m , min(three_m , five_m));
            if(dp[i] == two_m)p1++;
            if(dp[i] == three_m)p2++;
            if(dp[i] == five_m)p3++;
        }

        return dp[n-1];
    }
};
