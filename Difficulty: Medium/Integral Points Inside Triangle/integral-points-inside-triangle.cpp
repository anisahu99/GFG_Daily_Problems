//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int InternalCount(long long int p[], long long int q[],
                                long long int r[]) {
        // code here
         long long int px = p[0];
        long long int py = p[1];
        long long int qx = q[0];
        long long int qy = q[1];
        long long int rx = r[0];
        long long int ry = r[1];
        
        long long int dpqx = abs(px - qx);
        long long int dprx = abs(px - rx);
        long long int dqrx = abs(qx - rx);
        long long int dpqy = abs(py - qy);
        long long int dpry = abs(py - ry);
        long long int dqry = abs(qy - ry);
        
        
        long long int inpq = __gcd(dpqx,dpqy)-1;
        long long int inpr = __gcd(dprx,dpry)-1;
        long long int inqr = __gcd(dqrx,dqry)-1;
        
        long long int in = inpq + inpr + inqr + 3;
        
        
        long long int Area =abs(px*(qy-ry) + qx*(ry-py) + rx*(py-qy));
        long long int ans =(Area - in +2)/2;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long int p[2], q[2], r[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1];
        Solution ob;
        long long int ans = ob.InternalCount(p, q, r);
        cout << ans << "\n";
    }
}
// } Driver Code Ends