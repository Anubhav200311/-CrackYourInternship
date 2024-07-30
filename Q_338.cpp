class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int>arr(n+1);

        for(int i = 0 ; i <= n ; i++){

            bitset<18>b(i);
            
            
            arr[i] = b.count();
        }

        return arr;
    }
};
