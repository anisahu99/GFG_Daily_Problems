//{ Driver Code Starts

#include <iostream>
#include <regex>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string compareFrac(string str) {

        // Code here
        
        vector<string>v(2,"");
        int i = 0;
        for(auto it:str){
            if(it==' '){
                continue;
            }
            if(it==','){
                i++;
                continue;
            }
            v[i]+=it;
        }
        i=0;
        vector<int>num(4,0);
        for(auto it:v){
            for(auto its:it){
                if(its=='/'){
                    i++;
                    continue;
                }
                int add = its-'0';
                num[i]= num[i]*10+add;
            }
            i++;
        }
        int a = num[0]*num[3];
        int b = num[1]*num[2];
        if(a==b){
            return "equal";
        }
        return v[a<b];
    }
};


//{ Driver Code Starts.

int main() {
    Solution ob;
    int t;
    cin >> t;
    cin.ignore();
    for (int i = 0; i < t; i++) {

        string str;
        getline(cin, str);

        cout << ob.compareFrac(str) << endl;
    }
    return 0;
}

// } Driver Code Ends