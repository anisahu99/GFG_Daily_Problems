//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int countStr(long long int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        cout << countStr(n) << endl;
    }
return 0;
}
// } Driver Code Ends


long long int countStr(long long int n){
    //complete the function here
    if(n==1) return 3;
    if(n==2) return 8;
    if(n==3) return 19;
    if(n==4) return 39;
    long long int x=n*(n-1);
    long long int y=x/2;
    long long int z=y*(n-2);
    
    long long int ans=1+2*n+x+y+z;
    
    
    return ans;
}