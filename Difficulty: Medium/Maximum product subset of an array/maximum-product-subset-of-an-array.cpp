//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        long long int prod=1;
        int mini=INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i]<0){
                mini=max(arr[i],mini);
            }
            if(arr[i]!=0){
                prod=prod*arr[i];
                prod%=1000000007;
            }
        }
       if(prod<0){
           prod=prod/mini;
       }
       return prod;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends