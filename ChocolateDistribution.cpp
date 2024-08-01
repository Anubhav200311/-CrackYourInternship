 long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
    
        sort(a.begin() , a.end());
        
        long long min_ = a[m-1] - a[0];
        int b = 1;
        
        for(int i = m ; i < a.size() ; i++){
            
            min_ = min(min_ , a[i] - a[b]);
            b++;
        }
        
        return min_;
    }   
