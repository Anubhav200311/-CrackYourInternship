class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin() , nums.end());
        vector<vector<int>>ans;
        int n = nums.size();
        for(int i = 0 ; i < n - 2 ; i++){
            if(i > 0 && nums[i] == nums[i-1])continue;
            int left = i + 1;
            int right = n-1;

            while(right > left){
                int sum = nums[i] + nums[right] + nums[left];

                if(sum == 0){
                    ans.push_back({nums[i] , nums[right] , nums[left]});
                    while(left < right && nums[left] == nums[left+1])left++;
                    while(right > left && nums[right] == nums[right-1])right--;
                    left++;
                    right--;
                }
                else if(sum < 0)left++;
                else right--;

            }
        }

        return ans;
    }
};
