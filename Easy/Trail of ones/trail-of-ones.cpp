//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int numberOfConsecutiveOnes(int n) {
        // code here
         vector<int>fibo(n+1,0);
       fibo[1]=1;
       fibo[2]=2;
       int mod=1e9+7;
       for(int i=3;i<=n;i++){
           fibo[i]= (fibo[i-1]+ fibo[i-2]) %mod;
       }
       vector<int>ans(n+1);
       ans[0]=0;
       ans[1]=0;
       ans[2]=1;
       for(int i=3;i<=n;i++){
           ans[i]= ( (ans[i-1]*2 )%mod + fibo[i-2]%mod )%mod ;
       }
       return ans[n]%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends