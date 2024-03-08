//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s)
	{
	    // code here 
	    int freq[26]={0};
       for(int i=0;i<s.size();i++){
           freq[s[i]-'a']++;
           
       }
       
       
        int first=-1;
        int first_freq=0;
        int second=-1;
        int second_freq=0;
        for(int i=0;i<26;i++){
            if(freq[i]>0){
                if(first==-1){
                    first_freq=freq[i];
                    first=1;
                }
                else if(second==-1&&first_freq!=freq[i]){
                    second_freq=freq[i];
                    if(abs(first_freq-second_freq)!=1){
                        return false;
                    }
                    second=1;
                }
               else{
                   if(freq[i]==first_freq){
                       first++;
                   }
                   else if(freq[i]==second_freq){
                       second++;
                   }
                   else{
                       return false;
                   }
               }
            }
        }
if(second==-1){
    return true;
}
if((first==1)&&((first_freq-1==second_freq)||first_freq==1)){
    return true;
}
if((second==1)&&((second_freq-1==first_freq)||second_freq==1)){
    return true;
}
        return false;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends