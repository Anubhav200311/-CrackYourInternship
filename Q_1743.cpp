class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        map<int, vector<int>> mp;

        for (auto it : adjacentPairs) {
            mp[it[0]].push_back(it[1]);
            mp[it[1]].push_back(it[0]);
        }

        int first_element;
        for (auto it : mp) {
            if (it.second.size() == 1) {
                first_element = it.first;
                break;
            }
        }

        int n = adjacentPairs.size() + 1;
        vector<int> ans(n);
        ans[0] = first_element;
        ans[1] = mp[first_element][0];

        for (int k = 1; k < n - 1; ++k) {
            int prev = ans[k - 1];
            int curr = ans[k];
            for (int neighbor : mp[curr]) {
                if (neighbor != prev) {
                    ans[k + 1] = neighbor;
                    break;
                }
            }
        }

        return ans;
    }
};
