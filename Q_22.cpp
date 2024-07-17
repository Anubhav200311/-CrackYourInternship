class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int o_count = n;
        int c_count = n;
        string s = "(";
        vector<string> ans;
        fun(o_count - 1 , o_count , s , ans);
        return ans;
    }

    void fun(int o_count , int c_count , string s , vector<string>& ans){

        if(o_count == 0 && c_count == 0){
            ans.push_back(s);
            return;
        }

        if(c_count < o_count)return;
        
        if(o_count > 0){
            s.push_back('(');
            fun(o_count-1 , c_count , s , ans);
            s.pop_back();
        }
        if(c_count > 0){
            s.push_back(')');
            fun(o_count , c_count-1 , s , ans );
            s.pop_back();
        }
        

    }
};
