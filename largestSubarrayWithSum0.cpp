class Solution {
  public:
   int maxLen(vector<int>& arr, int n) {
       
    if(n == 1 && arr[1] == 0)return 1;
    unordered_map<int, int> mp; 
    int sum = arr[0];
    int len = 0;
    
    mp[sum] = 0;
    mp[0] = -1;

    for (int i = 1; i < n; i++) {
        sum += arr[i];

        if (mp.find(sum) != mp.end()) {
            len = max(len, i - mp[sum]);
        } else {
            mp[sum] = i;
        }
    }

    return len;
}

};
