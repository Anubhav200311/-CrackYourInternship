 int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        int arr[] = {x , y , z};
        vector<int>dp(n+1 , -1);
        
        dp[0] = 0;
        
        for(int i = 1 ; i <= n ; i++){
            
            for(int j : arr){
                if(i - j >= 0 && dp[i-j] != -1){
                    dp[i] = max(dp[i] , 1 + dp[i-j]);
                }
            }
        }
        
        return max(dp[n] , 0);
    }
