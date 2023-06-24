//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	#define mod 1000000007
	int findWaysUtil(int ind, int target, int arr[], vector<vector<int>> &dp){
     if(ind==0){

        if(target==0 && arr[0]==0)

        return 2;

        if(target==0 || arr[0]==target)

        return 1;

        return 0;

    }
    
    if(dp[ind][target]!=-1)
        return dp[ind][target]%mod;
        
    int notTaken = findWaysUtil(ind-1,target,arr,dp);
    
    int taken = 0;
    if(arr[ind]<=target)
        taken = findWaysUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= (notTaken + taken)%mod;
}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return findWaysUtil(n-1,sum,arr,dp)%mod;
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends