class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin() ,nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        subset(0 , nums , ans , temp);
        return ans;
    }

    void subset(int index , vector<int>&nums , vector<vector<int>>& ans, vector<int>temp){

        if(index == nums.size()){
            ans.push_back(temp);
            return;
        }
  
        temp.push_back(nums[index]);
        subset(index+1 , nums , ans ,temp);
        temp.pop_back();
        
        int newIndex = index + 1;
        while(newIndex < nums.size() && nums[newIndex] == nums[index])newIndex++;

        subset(newIndex , nums , ans , temp);
    }
};
