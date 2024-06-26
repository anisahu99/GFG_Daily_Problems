//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string s){
        // code here
        string str;
        stack<int>st;
        for(int i=0;i<=s.length();i++)
        {
           if(s[i]=='D') st.push(i+1);
           else if(s[i]=='I' || i==s.length())
           {
               st.push(i+1);
               while(!st.empty())
               {
                   str.push_back(st.top()+'0');
                   st.pop();
               }
           }
           
        }
        return str;
    }
};


//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 

// } Driver Code Ends