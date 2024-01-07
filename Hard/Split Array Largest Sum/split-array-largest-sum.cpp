//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int binarysearch(int arr[],int N,int mid){
        int sum=0;
        int freq=1;
        for(int i=0;i<N;i++){
            sum+=arr[i];
            if(sum>mid){
                freq++;
                sum=arr[i];
            }
        }
        return freq;
    }
    int solve(int arr[],int N,int K){
        int low=0,high=0;
        for(int i=0;i<N;i++){
            low=max(low,arr[i]);
            high+=arr[i];
        }
        int ans;
        while(low<=high){
            int mid=(low+high)/2;
            int curr=binarysearch(arr,N,mid);
            if(K>=curr){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }

   int splitArray(int arr[] ,int N, int K) {
        return solve(arr,N,K);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends