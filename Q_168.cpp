class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string str = "";
        while (columnNumber > 0) {
        int remainder = (columnNumber - 1) % 26;
        
        char c = 'A' + remainder;
        
        str = c + str;
        
        columnNumber = (columnNumber - 1) / 26;
    }

      //  str += (d - '0');

        return str;

    }
};
