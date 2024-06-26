//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int N, vector<string> Dictionary, string Pattern) {
        // code here
        vector<string> ans;
        for(int i=0;i<Dictionary.size();i++){
            string str="";
            bool flag=true;
            for(int j=0;j<Dictionary[i].length();j++){
                char ch=Dictionary[i][j];
                if(ch>='A'&&ch<='Z'){
                    str+=ch;
                }
                if(str==Pattern&&flag){
                    //cout<<Pattern<<"-"<<str<<endl;
                    ans.push_back(Dictionary[i]);
                    flag=false;
                }
            }
        }
        if(ans.size()==0)
        return {"-1"};
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends