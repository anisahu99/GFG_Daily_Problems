//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        // your code here
        int mini=INT_MAX;
 
 int n=arr.size();
 
 for(int i=0;i<arr.size();i++){
     
     
     mini=min(mini,(int)arr[i].size());
 }
 
  string ans="";
 for(int i=0;i<mini;i++){
  
  char ch=arr[0][i];
  
  int cnt=0;
  for(int j=1;j<n;j++){
      
      
      if(arr[j][i]!=ch){
           if(ans.empty()){
     return "-1";
 }else
          return ans;
      }
      else{
          cnt++;
      }
      
      
  }
  if(cnt==n-1){
      ans=ans+ch;
  }
 }
 return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends