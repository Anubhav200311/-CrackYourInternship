class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
        int n  = nums.size();
        if(n==1)return nums[0];
        int c = 0;
        for(int i = 1; i < n ; i++){
            if(nums[i-1] == nums[i]){
                c++;
                if(c+1 > n/2 )return nums[i];
            }else c = 0;
        }

        return -1;
    }
};
