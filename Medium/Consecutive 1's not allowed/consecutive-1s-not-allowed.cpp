//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
     long long int mod=1e9+7;

 ll countStrings(int n) {

     // code here

     int a = 1, b = 1;

    for (int i = 1; i <n; i++) {

       long long int temp =(a + b)%mod ;

        b = a;

        a = temp;

    }

    return (a+b)%mod;

 }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends