#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
	bool dfs(vector<int> adj[], int u, int parent, bool visited[]) {
	    visited[u] = true;
	    for(int v: adj[u]) {
	        if(!visited[v]) {
	            if(dfs(adj, v, u, visited))
	                return true;
	        }
	        else if(v != parent)
	            return true;
	    }
	    return false;
	}
	
	bool isCycle(int V, vector<int>adj[])
	{
	    bool visited[V] = {false};
	    for(int i=0; i<V; i++) {
	        if(!visited[i] && dfs(adj, i, -1, visited))
	            return true;
	    }
	    return false;
	}
};

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
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
