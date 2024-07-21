class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        //vector<int>diff;

        int gas_sum = 0 , cost_sum = 0;
        for(int i = 0 ; i < gas.size() ; i++){
            gas_sum += gas[i];
            cost_sum += cost[i];
            //diff.push_back(gas[i] - cost[i]);
        }
        if(cost_sum > gas_sum)return -1;
        int total =0 , index = 0;
        for(int i = 0 ; i < gas.size() ; i++){
            total += (gas[i] - cost[i]);
            if(total < 0){
                index = i+1;
                total = 0;
            }
        }

        return index;
    }
};
