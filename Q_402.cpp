class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() == k)return "0";
        int index_0 = 0;
        for(int i = 0 ; i <= k ; i++){
            if(num[i] == 0){
               index_0 = i;
               break;
            }
        }
    
        for(int i = 0 ; i < index_0 ; i++){
            num[i] == '#';
            k--;
        }

        for(int i = 1 ; i < num.size() ; i++){
            if(num[i] == '#')continue;
            
            if(k > 0 && num[i-1] >= num[i]){
                num[i-1] = '#';
                k--;
            }if(k == 0) break;
        }
        string s = "";
        for(int i = 0 ; i < num.size() ; i++){
            if(num[i] != '#')s += num[i];
        }

        return s;
    }
};
