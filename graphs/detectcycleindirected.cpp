#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
	
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	int count = 0;
	    int indegree[V] = {0};
	    for(int u=0; u<V; u++) {
	        for(int v: adj[u]) {
	            indegree[v]++;
	        }
	    }
	    queue<int> q;
	    for(int u=0; u<V; u++) {
	        if(indegree[u] == 0)
	            q.push(u);
	    }
	    while(!q.empty()) {
	        int u = q.front();
	        q.pop();
	        ++count;
	        for(int v: adj[u]) {
	           if(--indegree[v] == 0)
	                q.push(v);
	        }
	    }
	    return (count!=V);
	}
};


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
