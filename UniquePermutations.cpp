class Solution {
  public:
    vector<vector<int>> uniquePerms(vector<int> &arr ,int n) {
        // code here
        sort(arr.begin() , arr.end());
        vector<int>vis(n , 0);
        vector<vector<int>>ans;
        vector<int>temp;
        set<vector<int>>stk;
        fun(arr , n , vis , ans  , temp , stk);
        
        return ans;
    }
    
    void fun(vector<int>& arr , int n , vector<int>& vis , vector<vector<int>>& ans , vector<int>& temp , set<vector<int>>&stk){
        
        if(temp.size() == n){
            if(stk.find(temp) == stk.end()){
                ans.push_back(temp);
                stk.insert(temp);
            }
              //  ans.push_back(temp);
            return;
        }
        
        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                vis[i] = 1;
                temp.push_back(arr[i]);
                fun(arr , n , vis , ans , temp , stk);
                vis[i] = 0;
                temp.pop_back();
            }
        }
    }
};

