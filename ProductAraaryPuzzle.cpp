vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here    
        vector<long long int> product(n , 0);
        //map<int, int>pro ;
        long long pro = 1;
        int k = 0;
        for(int i : nums){
            
            if(i == 0){
                k++;
            }
            else {
                pro *= i;
            }
        }
        
        if(k > 1)return product;
        else if(k == 1){
            
            for(int i = 0 ; i < n ; i++){
                if(nums[i] == 0){
                    product[i] = pro;
                    return product;
                }
            }
        }else{
            for(int i = 0 ; i < n ; i++)
                product[i] = ((long long int)pro/nums[i]);
            
        }
        
        return product;
        
    }
