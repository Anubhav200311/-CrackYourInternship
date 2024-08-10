class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

        int m = board.size();
        int n = board[0].size();
        int wordLength = word.size();

        // vector<vector<int>>vis(m , vector<int>(n , 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] != '#' && board[i][j] == word[0]) {
                    if (helper(word, board, 0, i, j))
                        return true;
                }
            }
        }
        return false;
    }

    bool helper(string& word, vector<vector<char>>& board, int wordIndex,
                int row, int col) {

        if (wordIndex == word.size() - 1)
            return true;

        char ele = board[row][col];
        board[row][col] = '#';
        wordIndex++;
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int m = board.size();
        int n = board[0].size();
        for (pair<int, int> i : dir) {
            int nrow = row + i.first;
            int ncol = col + i.second;
            if (min(nrow, ncol) >= 0 && nrow < m && ncol < n &&
                board[nrow][ncol] != '#' &&
                word[wordIndex] == board[nrow][ncol]) {
                if (helper(word, board, wordIndex, nrow, ncol))
                    return true;
            }
        }
        board[row][col] = ele;
        return false;
    }
};
