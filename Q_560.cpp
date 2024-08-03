
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        map<int, int> mp; // sum , index
        int sum = 0;
        int count = 0;
        mp[sum] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = sum - k;
            if (mp.find(rem) != mp.end()) {
                count += mp[rem];
            }
            mp[sum]++;
        }

        return count;
    }
};
