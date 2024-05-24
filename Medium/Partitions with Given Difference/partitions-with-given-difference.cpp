//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    const int MOD = 1e9 + 7;
        
        int fun(int i, vector<int> &arr, int n, int s, int s1, vector<vector<int>> &dp) {   
            if (i == n) {
                if (s1 == s)
                    return 1;
                else
                    return 0;
            }
        
            if (dp[i][s1] != -1)
                return dp[i][s1];
        
            int t = 0, nt = 0;
        
            if (s1 + arr[i] <= s) { // Ensure we do not exceed the required sum
                t = fun(i + 1, arr, n, s, s1 + arr[i], dp);
            }
            nt = fun(i + 1, arr, n, s, s1, dp);
        
            return dp[i][s1] = (t + nt) % MOD;
        }
        
        int countPartitions(int n, int d, vector<int>& arr) {
            int sum = 0;
            for (int i = 0; i < n; i++)
                sum += arr[i];
            if ((sum - d) < 0 || (sum - d) % 2 != 0)
                return 0;
            vector<vector<int>> dp(n + 1, vector<int>((sum - d) / 2 + 1, -1));
            int ans = fun(0, arr, n, (sum - d) / 2, 0, dp);
            return ans;
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends