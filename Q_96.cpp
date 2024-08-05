class Solution {
public:
    int numTrees(int n) {

        vector<int>numTrees(n+1 , 1);
        
        for(int nodes = 2 ; nodes < n+1 ; nodes++){
            int total = 0;
            for(int root = 1 ; root < nodes +1 ; root++){
                int leftTrees = root - 1;
                int rightTrees = nodes - root;
                total += numTrees[leftTrees] * numTrees[rightTrees];
            }
            numTrees[nodes] = total;
        }

        return numTrees[n];
    }
};
