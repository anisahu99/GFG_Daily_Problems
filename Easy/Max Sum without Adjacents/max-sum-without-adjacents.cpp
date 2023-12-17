//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    vector<vector<int>> dp;
    int solve(int i,int flag,int *arr,int &n){
        if(i==n) return 0;
        if(dp[i][flag]!=-1) return dp[i][flag];
        
        int include=0;
        if(!flag){
            include=arr[i]+solve(i+1,1,arr,n);
        }
        int exclude=solve(i+1,0,arr,n);
        
        return dp[i][flag]=max(include,exclude);
    }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int &n) {
	    // code here
	    dp.resize(n,vector<int>(2,-1));
	    return solve(0,0,arr,n);
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends