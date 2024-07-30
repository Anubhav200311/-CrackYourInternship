class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin() , nums.end());
       
        vector<int>temp;
        vector<vector<int>>ans;
        vector<int>fre(nums.size() , 0);
        set<vector<int>>st;
        permute( nums , temp , ans, fre , st);
        return ans;
    }
    void permute(vector<int>&nums ,vector<int>& temp , vector<vector<int>>&ans , vector<int>& fre , set<vector<int>>&st){

        if(temp.size() == nums.size()){
            if(st.find(temp) == st.end()){
                ans.push_back(temp);
                st.insert(temp);
            }
            //ans.push_back(temp);
            return;
        }
        for(int i = 0 ; i < nums.size(); i++){
            if(!fre[i]){
                temp.push_back(nums[i]);
                fre[i] = 1;
                permute(nums , temp , ans , fre , st);
                fre[i] = 0;
                temp.pop_back();
            }
        }
    }
};
