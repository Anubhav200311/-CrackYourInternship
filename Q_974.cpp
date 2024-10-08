class Solution {
public:
     int subarraysDivByK(std::vector<int>& nums, int k) {
        std::unordered_map<int, int> mp;
        int sum = 0;
        int count = 0;
        mp[0] = 1;  

        for (int num : nums) {
            sum += num;
            int rem = sum % k;

            
            if (rem < 0) {
                rem += k;
            }

            
            if (mp.find(rem) != mp.end()) {
                count += mp[rem];
            }

            mp[rem]++;
        }

        return count;
    }
};
