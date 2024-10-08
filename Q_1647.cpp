class Solution {
public:
    int minDeletions(string s) {
        
        unordered_map<char , int>fre;

        for(char c : s)fre[c]++;

        unordered_set<int>st;
        int count = 0;
        for(auto it : fre){

            while(st.find(it.second) != st.end()){
                count++;
                it.second--;
            }
            if(it.second > 0)st.insert(it.second);
        }

        return count ;
    }
};
