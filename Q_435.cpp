class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
                  [](vector<int>& a, vector<int>& b) {
                      return a.back() < b.back();
                  });
        
        int count = 0;
        vector<vector<int>>helper;
        helper.push_back(intervals[0]);
        int k = 0;
        for(int i = 1 ; i < intervals.size() ; i++){
            
            if(intervals[i][0] < helper[k][1])count++;
            else{
                helper.push_back(intervals[i]);
                k++;
            }
        }

        return count;
    }
};
