class Solution {
public:
    int leastInterval(vector<char>& tasks, int k) {
        
        vector<int>arr(26 , 0);

        for(char c : tasks){
            arr[c - 'A']++;
        }
        
        int maxFC = 0 , maxF = 0;
        for(int i : arr){
            
            if(i == maxF)maxFC++;

            if(i > maxF){
                maxF = i;
                maxFC = 1;
            }
        }

        int gaps = maxF - 1;
        int gaps_len = k - (maxFC - 1);
        int avail_slots = gaps * gaps_len;
        int avail_task = tasks.size() - maxFC * maxF;

        int idle = max(0, avail_slots - avail_task); 
        return tasks.size() + idle;
    }
};
