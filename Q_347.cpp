class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> fre;

        for (int i : nums)
            fre[i]++;

        priority_queue < pair<int, int>,
            vector<pair<int, int>>, greater<pair<int, int>>> pq;
       
        for(auto it : fre){
            pq.push({it.second , it.first});
            if(pq.size() > k)pq.pop();
        }
        vector<int>ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
