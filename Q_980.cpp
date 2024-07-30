class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        int row , col ;
        int empty = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0; j < n ; j++){
                if(grid[i][j] == 1){
                    row = i;
                    col = j;
                }
                if(grid[i][j] == 0)empty++;
            }
        }
        int k = 0;
    
        fun(row , col , grid , k , empty + 1);

        return k;
    }

    void fun(int row , int col , vector<vector<int>>& grid , int& k , int empty){

        if(grid[row][col] == 2){
            if(empty == 0)
                k++;
            return;
        }

        vector<pair<int , int>>dir = {{1,0} , {-1,0} , {0,1} , {0,-1}};
        int m = grid.size();
        int n = grid[0].size();
        int temp = grid[row][col];
        grid[row][col] = -1;

        for(pair<int , int> it : dir){
            
            int nrow = row + it.first;
            int ncol = col + it.second;

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] != -1){
                //grid[nrow][ncol] = -1;
               fun(nrow , ncol , grid , k , empty - 1);
               //grid[nrow][ncol] = 0;
            }
        }

        grid[row][col] = temp;
        
    }
};
