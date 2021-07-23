#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    queue<int> q;
        bool visited[V] = {false};
        int dist[V];
        visited[0] = true;
        q.push(0);
        dist[0] = 0;
    
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int v: adj[u]) {
                if(!visited[v]) {
                    q.push(v);
                    visited[v] = true;
                    dist[v] = dist[u] + 1;
                    if(v == X)
                        return dist[v];
                }
            }
        }
        return -1;
	}
};

int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}
