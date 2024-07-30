class Solution {
public:
    string addBinary(string a, string b) {
        if (b.size() > a.size()) {
            swap(a, b);
        }

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        string result = "";
        int carry = 0;
        int b_len = b.size();
        int a_len = a.size();

        for (int i = 0; i < a_len; i++) {
            int bit_a = a[i] - '0'; 
            int bit_b = i < b_len ? b[i] - '0' : 0; 

           
            int sum = bit_a + bit_b + carry;
            carry = sum / 2;
            result.push_back((sum % 2) + '0'); 
        }

        if (carry) {
            result.push_back('1');
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
