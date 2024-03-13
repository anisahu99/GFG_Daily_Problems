//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    vector<int> matrixDiagonally(vector<vector<int>>&mat)
    {
         //Your code here
         vector<int>ans ;
        ans.push_back(mat[0][0]) ;
        int n = mat.size() ;
        for(int i=1;i<n;i++){
           if(i&1){
            int j=i,k=0 ;
            while(j>=0 && k>=0){
                ans.push_back(mat[k][j]);
                j-- ;
                k++ ;
                
            }
                
            }
            else{
                int j=0,k=i ;
                while(j>=0 && k>=0){
                    ans.push_back(mat[k][j]) ;
                    j++ ;
                    k-- ;
                }
            }
        }
        
        if(n&1){for(int i=1;i<n;i++){
            
           if(i&1){
                            int j=n-1,k=i ;
            while(j>=1 && k<n){
                    ans.push_back(mat[k][j]);
                    j-- ;
                    k++ ; 
            }
          
           }
                
     else{
              int k=n-1 ,j=i ;
                 while(j<n && k>=0){  
                ans.push_back(mat[k][j]);
                    j++ ;
                    k-- ;
                     
                 }
                }
                   
                }
        }
        else{
            for(int i=1;i<n;i++){
            
           if(i&1){
            int k=n-1 ,j=i ;
                 while(j<n && k>=0){  
                ans.push_back(mat[k][j]);
                    j++ ;
                    k-- ;
                     
                 }
           }
                
     else{
                     int j=n-1,k=i ;
            while(j>1 && k<n){
                    ans.push_back(mat[k][j]);
                    j-- ;
                    k++ ; 
            }
                }
                   
                }
            
        }
                return ans ;
    }
};


//{ Driver Code Starts.
int main()
{
    int T;
    cin>>T;
  
    while(T--)
    {
        int n;
        int k=0;
        //cin>>k;
        cin>>n;
        vector<vector<int>>mat(n, vector<int>(n));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> mat[i][j];
            }
        }
        Solution obj;
        vector<int>ans = obj.matrixDiagonally(mat);
        for(auto i: ans)cout << i << " ";
        cout << "\n";
        
       
    }
}
// } Driver Code Ends