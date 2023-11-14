//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    using ll = long long int;
    ll mod = 1e9+7;
    int distinctSubsequences(string s)
    {
        int n = s.size(),cnt =0,dup=0,sum=3;
      
       vector<ll>dp(n+1,1),seen(26,-1);
       for(int i =1 ;i<=n ;i++){
           dp[i] = (dp[i-1]*2)%mod;
           
           if(seen[s[i-1]-'a']>-1) dp[i] = (dp[i]- dp[ seen[s[i-1]-'a']-1 ] + mod)%mod;
        
           seen[s[i-1]-'a'] = i;
       }
       return dp[n];
    }
    string betterString(string str1, string str2) {
        return distinctSubsequences(str1)>=distinctSubsequences(str2)?str1:str2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends