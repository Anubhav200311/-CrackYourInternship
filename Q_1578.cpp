class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        stack<int>stk;
        int total_time = 0;
        stk.push(neededTime[0]);
        for(int i = 1 ; i < colors.size()  ; i++){
            if(colors[i] == colors[i-1]){
                if(stk.top() < neededTime[i]){
                    total_time += stk.top();
                    stk.pop();
                    stk.push(neededTime[i]);
                }
                else total_time += neededTime[i];
            }else stk.push(neededTime[i]);
        }

        return total_time;
    }
};
