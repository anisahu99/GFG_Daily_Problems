//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        // Code Here
         int n = arr.size();
        vector<int> rs; //used vector to store the index seprat for row / col
        vector<int> cs;
        
        
        for (int i = 0; i < n; i++) {
            bool rowSym = true;
            bool colSym = true;
            int x = 0, y = n - 1;
            while (x < y) { //this loop is used to check that row/col is palindrom or not
                if (arr[i][x] != arr[i][y]) {
                    rowSym = false;
                }
                if (arr[x][i] != arr[y][i]) {
                    colSym = false;
                }
                if (rowSym==false && colSym==false){ // just to optimize the code 
                    break;
                }
                x++;
                y--;
            }
            if (rowSym) {
                rs.push_back(i);
            }
            if (colSym) {
                cs.push_back(i);
            }
        }
        
        string ans = "";
        if (!rs.empty()) {
            ans += to_string(rs.front()); //you can use rs[0]; 
            ans += ' ';
            ans += 'R';
        } else if (!cs.empty()) {
            ans += to_string(cs.front());
            ans += ' ';
            ans += 'C';
        } else {
            ans = "-1";
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t, n, i, j, flag, k;
    cin >> t;

    while (t--) {
        cin >> n;
        vector<vector<int>> a(n, vector<int>(n));

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                cin >> a[i][j];
        }
        Solution ob;
        cout << ob.pattern(a) << endl;
    }
    return 0;
}
// } Driver Code Ends