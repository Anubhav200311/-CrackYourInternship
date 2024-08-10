class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       //Your code here
       int cost_sum = 0;
       int gas_sum = 0;
       
       for(int i = 0  ; i < n ; i++){
           cost_sum += p[i].distance;
           gas_sum += p[i].petrol;
       }
       
       if(cost_sum > gas_sum)return -1;
       
       int total = 0 , index = 0;
       for(int i = 0 ; i < n ; i++){
           total += (p[i].petrol - p[i].distance);
           if(total < 0){
               total = 0;
               index = i + 1;
           }
       }
       
       return index;
    }
};
