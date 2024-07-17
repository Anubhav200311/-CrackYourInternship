class Solution {
public:
    string reverseWords(string s) {
        vector<string> helper;
        string word = "";
        
        // Traverse the input string
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == ' '){
                if (!word.empty()) {
                    helper.push_back(word);
                    word = "";
                }
            }
            else {
                word += s[i];
            }
        }
        if (!word.empty()) {
            helper.push_back(word);
        }

        string result = "";
        for(int i = helper.size() - 1 ; i >= 0 ; i--){
            result += helper[i];
            if (i != 0) {
                result += ' ';
            }
        }

        return result;
    }
};
