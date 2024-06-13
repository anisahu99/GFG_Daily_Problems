//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    int padovanSequence(int n)
    {
       //code here
       if(n == 0 || n==1 || n==2 ){
           return 1;
       }
       
       vector<int> padovan(n+1, 0);
       padovan[0] = 1;
       padovan[1] = 1;
       padovan[2] = 1;
       int mod = 1e9+7;
       for(int i = 3; i<=n; i++){
           padovan[i] = (padovan[i-2]+padovan[i-3])%mod;
       }
       
       return padovan[n];
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
    	cout<<ob.padovanSequence(n)<<endl;
    }
    return 0;
}
// } Driver Code Ends