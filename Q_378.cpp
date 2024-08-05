class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();

        int div = k / n;
        int rem = k % n;
        
        if(div + rem < n * n)
            return matrix[div][rem];
        return -1;
    }
};
