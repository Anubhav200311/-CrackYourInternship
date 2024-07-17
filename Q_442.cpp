class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int , int>mp;
        vector<int> ans;
        for(int i : nums)mp[i]++;

        for(auto it : mp){
            if(it.second == 2)ans.push_back(it.first);
        }

        return ans;
    }
};
