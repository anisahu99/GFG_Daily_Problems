//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:

    bool ans = 0;
    
    void solve(int coins[], int index, int sum, int &N, vector<vector<int>> &dp) {
        
        if(sum != 0 && (sum == 2024 || sum % 20 == 0 || sum % 24 == 0)) {
            ans = 1;
            return;
        }
        
        if(index >= N || sum > 2024) return;
        if(dp[index][sum] != -1) return;
        
        solve(coins, index + 1, sum, N, dp);
        solve(coins, index + 1, sum + coins[index], N, dp);
        
        dp[index][sum] = ans;
    }    
    
    
    int isPossible(int N , int coins[]) {
        
        int total = 0;
        for(int i = 0; i < N; i++) total += coins[i];
        
        vector<vector<int>> dp(N, vector<int> (total + 1, -1));
        solve(coins, 0, 0, N, dp);
    
        return ans;
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends