class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int sum = 0;
        for(int i = 0 ; i < k ; i++) sum += cardPoints[i];

        int currentSum = sum;
        int n = cardPoints.size();
        for(int i = k-1 ; i >= 0 ; i--){

            currentSum -= cardPoints[i];
            currentSum += cardPoints[n + i - k];

            sum = max(sum , currentSum);
        }
        return sum;
    }
};
