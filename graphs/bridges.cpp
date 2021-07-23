#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    bool dfs(int u, vector<int> adj[], int c, int d, int parent[], int low[], int disc[], int &time) {
        low[u] = disc[u] = ++time;
        for(int v: adj[u]) {
            if(disc[v] == -1) {
                parent[v] = u;
                if(dfs(v, adj, c, d, parent, low, disc, time))
                    return true;
                low[u] = min(low[u], low[v]);
                if(u==c && v==d || u==d && v==c) {
                    if(low[v]>disc[u]) 
                        return true;
                }
            }
            else if(v != parent[u]) {
                low[u] = min(low[u], disc[v]);
            }
        }
        return false;
    }
    
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        int disc[V];
        fill(disc, disc+V, -1);
        int low[V];
        int parent[V] = {-1};
        int time = 0;
        for(int i=0; i<V; i++) {
            if(disc[i] == -1 && dfs(i, adj, c, d, parent, low, disc, time))
                return 1;
        }
        
        return 0;
    }
};

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
