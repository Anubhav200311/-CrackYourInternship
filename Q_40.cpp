class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;

        fun(0, target, ans, temp, candidates);

        return ans;
    }

    void fun(int index, int target, vector<vector<int>>& ans, vector<int>& temp,
             vector<int>& candidates) {

        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (index >= candidates.size() || candidates[index] > target) {
            return;
        }

        temp.push_back(candidates[index]);
        fun(index + 1, target - candidates[index], ans, temp, candidates);
        temp.pop_back();

        int nextIndex = index + 1;
        while (nextIndex < candidates.size() &&
               candidates[nextIndex] == candidates[index])
            nextIndex++;

        fun(nextIndex, target, ans, temp, candidates);
    }
};
