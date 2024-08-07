class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        
        vector<vector<int>>res;
        vector<int>temp;
        helper(1 , temp , res , n , k);
        return res;
    }
    void helper(int start , vector<int>& temp , vector<vector<int>>& res , int n , int k){
            if(temp.size() == k){
                res.push_back(temp);
                return;
            }

            for(int i = start ; i<= n ; i++){
                temp.push_back(i);
                helper(i + 1, temp , res , n , k);
                temp.pop_back();
            }
        }
};
