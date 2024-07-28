class Solution {
public:
    string decodeString(string s) {

        stack<char> stk;
        stack<int> num;
        for (char c : s) {

            if (c != ']')
                stk.push(c);
            else {
                string temp = "";

                while (stk.top() != '[') {
                    temp = stk.top() + temp;
                    stk.pop();
                }
                stk.pop();
                string number = "";

                while (!stk.empty() && isdigit(stk.top())) {
                    number = stk.top() + number;
                    stk.pop();
                }
                int n = stoi(number);

                while (n--) {
                    for (char ch : temp)
                        stk.push(ch);
                }
            }
        }

        s = "";
        while (!stk.empty()) {
            s = stk.top() + s;
            stk.pop();
        }

        return s;
    }
};
