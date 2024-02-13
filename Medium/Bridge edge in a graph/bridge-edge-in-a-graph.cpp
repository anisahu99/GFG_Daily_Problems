//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    void dfs(int node,int parent,int &timer,vector<int> &t,vector<int> &low,vector<int>&vis,vector<int> adj[],int &c,int &d,int &ans){
        ++timer;
        t[node]=low[node]=timer;
        vis[node]=1;
        for(int nbr:adj[node]){
            if(nbr==parent) continue;
            if(!vis[nbr]){
                dfs(nbr,node,timer,t,low,vis,adj,c,d,ans);
            }
            if(vis[nbr]){
                low[node]=min(low[node],low[nbr]);
            }
            if(low[nbr]>t[node]){
                if((node==c||node==d)&&(nbr==c||nbr==d)) ans=1;
            }
        }
    }
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<int> vis(V),low(V),t(V);
        int timer=0;
        int ans=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,-1,timer,t,low,vis,adj,c,d,ans);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends