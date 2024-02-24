//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    int maxSum(int n)
    {
        //code here.
        //base case
        if(n==0 or n==1) return n;
        // the maximum result can be obtained, if we divide the number and the sum of the
        //new numbers is more than the given integer else we don't need to divide
        return max(n,maxSum(n/2)+maxSum(n/3)+maxSum(n/4));
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        Solution ob;
        cout<<ob.maxSum(n)<<"\n";
    }
    return 0;
}
// } Driver Code Ends