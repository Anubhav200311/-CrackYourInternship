class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        vector<int>ans(temperatures.size() , 0);
        stack<pair<int , int>>stk;

        for(int i = 0 ; i < temperatures.size() ; i++){
            while(!stk.empty() && stk.top().first < temperatures[i]){
                pair<int , int> it = stk.top();
                stk.pop();
                ans[it.second] = i - it.second;
            }
            stk.push({temperatures[i] , i});
        }

        return ans;
    }
};
