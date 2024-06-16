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
    vector<int> getPrimes(int n) {
        // code here
        vector<int> nums(n+1);
        for(int i = 0;i <= n; i++)
            nums[i] = i;
        // Sieve of Eratosthenes
        for(int i = 2;i*i <= n; i++) {
            if(nums[i] == i) {
                for(int j = i*i;j <= n; j+=i)
                    nums[j] = i;
            }
        }

        vector<int> ans(2, -1);
        int s = 2, e = n-2;

        while(s <= e) {
            if(nums[s] == s && nums[e] == e) {
                if(ans[0] == -1) {
                    ans[0] = nums[s];
                    ans[1] = nums[e];
                }
            }

            s++; e--;
        }
        
        return ans;
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
        vector<int> res = obj.getPrimes(n);

        Array::print(res);
    }
}

// } Driver Code Ends