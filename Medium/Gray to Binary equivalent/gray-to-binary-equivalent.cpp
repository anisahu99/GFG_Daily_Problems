//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    string DecimalToBinary(int num){
        string str;
        while(num){
            if(num & 1) // 1
                str+='1';
            else // 0
                str+='0';
            num>>=1; // Right Shift by 1  
        }    
        reverse(str.begin(),str.end());
        return str;
    }
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        string s = DecimalToBinary(n);
        int prev = (s[0] == '1')?1:0;
        // cout<<prev<<endl;
        int ans = (prev)<<(s.size()-1);
        // cout<<ans<<endl;
        for(int i = 1;i<s.size();i++){
            prev = ((s[i] == '1')?1:0)^prev;
            // cout<<prev<<endl;    
            ans+=((prev)<<(s.size()-1-i));
            // cout<<ans<<endl;
        }
        return ans;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t,n;
    cin>>t;//testcases
    while(t--)
    {
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
    }
}

// } Driver Code Ends