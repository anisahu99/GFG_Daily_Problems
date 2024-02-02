//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int f=0,sum=0, x=0;
        if(s[0]=='-'){
            f=1;
        }else{
            if(s[0]<48 || s[0]>57)return -1;
            x=s[0]-48;
            sum=sum*10+x;
        }
        for(int i=1; i<s.length(); i++){
            if(s[i]<48 || s[i]>57)return -1;
            x=s[i]-48;
            sum=sum*10+x;
        }
        return f==1 ? -sum : sum;
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		Solution ob;
		cout<<ob.atoi(s)<<endl;
	}
}
// } Driver Code Ends