//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	typedef pair<int,int> P;
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        
        priority_queue <P, vector<P>, greater<P> > pq;
        vector<int> vis(V,0);
        pq.push({0,0});
        int sum=0;
        while(!pq.empty()){
            auto temp=pq.top();pq.pop();
            int wt=temp.first;
            int node=temp.second;
            if(vis[node]) continue;
            vis[node]=1;
            sum+=wt;
            for(vector<int> next:adj[node]){
                if(!vis[next[0]]){
                    pq.push({next[1],next[0]});
                }
                
            }
        }
        return sum;
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends