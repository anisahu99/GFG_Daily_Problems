//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
     int minValue(string s, int k){
       map<int,int>mp;
       for(char c:s)  mp[c]++;
       priority_queue<int>p;
       for(auto it:mp) p.push(it.second);
       while(k>0){
           auto it=p.top();
           it--;
           p.pop();
           k--;
           if(it>0){
               p.push(it);
           }
       }
       long ans=0;
       while(p.size()>0){
           auto it=p.top();
           p.pop();
           ans+=(it*it);
       }
       return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
    return 0;
}
// } Driver Code Ends