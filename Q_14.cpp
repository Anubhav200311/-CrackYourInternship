class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        int len = strs[0].size();
        string res = "";
        for(int i = 0 ; i < len ; i++){

            for(string it : strs){

                if(i == it.size() || it[i] != strs[0][i])return res;
            }
            res += strs[0][i];
        }

        return res;
    }
};
