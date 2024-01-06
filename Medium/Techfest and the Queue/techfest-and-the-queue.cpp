//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	int sumOfPowers(int a, int b){
	    // Code here
	    vector<int> primesCount(b + 1, 0);

        for (int i = 2; i <= b; i++) {
            if (primesCount[i] == 0) {
                for (int j = i; j <= b; j += i) {
                    int temp = j;
                    while (temp % i == 0) {
                        primesCount[j]++;
                        temp /= i;
                    }
                }
            }
        }

        int sum = 0;
        for (int i = a; i <= b; i++) {
            sum += primesCount[i];
        }

        return sum;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends