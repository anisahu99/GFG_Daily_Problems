//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  //copy
    int minCandy(int N, vector<int> &ratings) {
        // code here
        vector<int> left(N, 1);
        vector<int> right(N, 1);

        // Traverse from left to right
        for (int i = 1; i < N; i++) {
            if (ratings[i] > ratings[i - 1]) {
                left[i] = left[i - 1] + 1;
            }
        }

        // Traverse from right to left
        for (int i = N - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                right[i] = right[i + 1] + 1;
            }
        }

        int totalCandies = 0;
        for (int i = 0; i < N; i++) {
            totalCandies += max(left[i], right[i]);
        }

        return totalCandies;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends