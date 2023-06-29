//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    //Floyd’s Cycle Detection Algorithm || C++
int digSq(int n)
    {
        int ans=0;
        while(n){
            int temp=n%10;
            ans+=temp*temp;
            n/=10;
        }
        return ans;
    }
    
    int nextHappy(int n){
        while(n){
            n++;
          int slow=n;
          int fast=n;
          do{
            slow=digSq(slow);
            fast=digSq(digSq(fast));
          }while(slow!=fast);
          if (slow==1)
          return n;
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.nextHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends