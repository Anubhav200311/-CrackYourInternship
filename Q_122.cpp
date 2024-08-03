class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int profit = 0;
        int n = prices.size();
        int i = 0;
        while(i < n-1){

            if(prices[i] < prices[i+1]){
                int buy = prices[i];
                i = i + 1;
                while(i < n - 1 && prices[i] < prices[i+1])i++;
                profit += (prices[i] - buy);
            }
            i++;
        }

        return profit;
    }
};
