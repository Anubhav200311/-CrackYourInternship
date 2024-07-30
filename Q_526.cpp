class Solution {
public:
    int countArrangement(int n) {
        
       // int k ;
        vector<int>fre(n + 1 , 0);
        vector<int>temp;
        int k = 0;
        fun( k , n , temp , fre , 1);
        return k;
    }
    void fun(int& k , int n , vector<int>&temp , vector<int>& fre , int pos){

        if(temp.size() == n){
            k++;
            return;
        }
     
        for(int i = 1 ; i <= n ; i++){

            if(!fre[i] && (i % pos == 0 || pos %i == 0)){
                fre[i] = 1;
                temp.push_back(i);
                fun(k , n , temp , fre , pos + 1);
                fre[i] = 0;
                temp.pop_back();
            }
        }
    }
};
