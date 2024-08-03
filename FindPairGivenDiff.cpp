//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
     sort(arr.begin(), arr.end());  // Sort the array

    int i = 0, j = 1;

    while (j < n) {
        int diff = arr[j] - arr[i];

        if (i != j && diff == x) {
            return 1;  // Pair found with the required difference
        } else if (diff < x) {
            j++;  // Increase j to increase the difference
        } else {
            i++;  // Increase i to decrease the difference
        }

        // Ensure i and j are not the same
        if (i == j) {
            j++;
        }
    }

    return -1;  // No such pair found
}

};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        int res = obj.findPair(n, x, arr);

        cout << res << endl;
    }
}

// } Driver Code Ends
