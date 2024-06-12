//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countNumberswith4(int n) {
        // code here
        int count = 0;
        int temp;
        
        for(int x = 1; x <= n; x++)
        {
            temp = x;
            
            while(temp)
            {
                if(temp%10 == 4) 
                {
                    count++;break;
                }
                
                temp = temp / 10;
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends