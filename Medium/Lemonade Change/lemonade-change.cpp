//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool lemonadeChange(int N, vector<int> &bills) {
        // code here
        int five=0,ten=0,twenty=0;
        for(int &bill:bills){
            if(bill==5){
                five++;
            }
            else if(bill==10){
                if(five>0){
                    five--;
                    ten++;
                }else{
                    return false;
                }
            }
            else if(bill==20){
                if(ten>0){
                    ten--;
                    if(five>0){
                        five--;
                    }
                    else{
                        return false;
                    }
                }
                
                else if(five>2){
                    five-=3;
                }
                else{
                    return false;
                }
                twenty++;
            }
        }
        return true;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends