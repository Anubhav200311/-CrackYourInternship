class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int , int>mp;

        for(int i = 0 ; i < nums1.size() ; i++)mp[nums1[i]] = i;

        stack<int>stk;
        vector<int>v(nums1.size() , -1);
        for(int i = 0 ; i < nums2.size() ; i++){

            int curr = nums2[i];

            while(!stk.empty() && curr > stk.top()){
                v[mp[stk.top()]] = curr;
                stk.pop();
            }
            if(mp.find(curr) != mp.end())stk.push(curr);
        }

        return v;
    }
};
