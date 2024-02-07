//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	
	int solve(int n,vector<int> &dp){
	    if(n<0) return INT_MAX;
	    if(dp[n]!=-1) return dp[n];
	    int sq=sqrt(n);
	    int square=sq*sq;
	    if(n-square==0) return 1;
	    int ans=INT_MAX;
	    for(int i=sq;i>=1;i--){
	        ans=min(ans,solve(n-(i*i),dp));
	    }
	    return dp[n]=1+ans;
	}
	
	int MinSquares(int n)
	{
	    // Code here
	    vector<int> dp(n+1,-1);
	    return solve(n,dp);
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends