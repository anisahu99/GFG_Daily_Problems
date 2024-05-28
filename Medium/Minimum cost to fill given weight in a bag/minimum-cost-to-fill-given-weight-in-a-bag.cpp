//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimumCost(int n, int w, vector<int> &cost) {
        // code here
        int table[w+1];
        for(int i=0;i<=w;++i){
            table[i] = -1;
        }
        table[0] = 0;
        for(int i=1;i<=n;++i){
            if(i > w) break;
            table[i] = cost[i-1];
        }
        for(int i = 2;i<=w;++i) {
            int minCost = 1e5+5;
            for(int j = 1;j<=n;++j){
                if(cost[j-1] == -1 || i < j) continue;
                if(table[i-j] == -1) continue;
                minCost = min(minCost,cost[j-1]+table[i-j]);
            }
            if(minCost == 1e5+5) continue;
            table[i] = minCost;
        }
        return table[w];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends