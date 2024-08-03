//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        stack<int> st;
        int n=mat.size();
        for(int i=0;i<n;i++)
        st.push(i);
       
        while(st.size()!=1)  
        {
            int a=st.top();
            st.pop();
            int b=st.top();
            if(mat[a][b]==0)
            {
                st.pop();
                st.push(a);
            }
        }
        
        int cele=st.top();
        
        for(int j=0;j<n;j++)
        {
            if(j==cele) continue;
            
            if(mat[cele][j]!=0)
             return -1;
             if(mat[j][cele]!=1)
             return -1;
        }
         return cele;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends