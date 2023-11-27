//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    vector<int> par;
    vector<int> rank1;
    int find_parent(int val){
        if(par[val]==val) return val;
        par[val]=find_parent(par[val]);
        return par[val];
    }
    void union_( int a, int b) 
    {
        int a_parent=find_parent(a);
        int b_parent=find_parent(b);
        if(a_parent==b_parent) return;
        if(rank1[a_parent]==rank1[b_parent]){
            par[b_parent]=a_parent;
            rank1[a_parent]++;
        }else{
            if(rank1[a_parent]>rank1[b_parent]){
                par[b_parent]=a_parent;
            }
            else{
                par[a_parent]=b_parent;
            }
        }
        return;
    }
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y)
    {
        if(find_parent(x)==find_parent(y)) return true;
        return false;
    }
    public:
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    par.resize(V);rank1.resize(V,0);
	    for(int i=0;i<V;i++){
	        par[i]=i;
	    }
	    for(int u=0;u<V;u++){
	        for(int &v:adj[u]){
	        if(isConnected(u,v)&&u<v){
	            return 1;
	        }
	        else{
	            union_(u,v);
	        }
	    }
	    }
	    return 0;
	}
};



















//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends