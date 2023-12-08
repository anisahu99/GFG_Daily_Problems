//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    void SieveOfEratosthenes(bool *prime,int n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    
  
    for (int p = 2; p * p <= n; p++) { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) { 
            // Update all multiples of p greater than or 
            // equal to the square of it numbers which are 
            // multiple of p and are less than p^2 are 
            // already been marked. 
            for (int i = p * p; i <= n; i += p) 
                prime[i] = false; 
        } 
    } 
  
} 
    int minNumber(int arr[],int n)
    {
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        int N=1e6+3;
        bool prime[N + 1]; 
        memset(prime, true, sizeof(prime));
        prime[0]=0;
        prime[1]=0;
        SieveOfEratosthenes(prime,N);
        for(int i=sum;i<=N;i++){
            if(prime[i]) return i-sum;
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends