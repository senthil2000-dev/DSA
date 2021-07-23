#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to return Breadth First Traversal of given graph.
	vector<int> bfs(vector<int> adj[], int src, bool visited[]) {
	    vector<int> ans;
	    queue<int> q;
	    q.push(src);
	    visited[src] = true;
	    while(!q.empty()) {
	        int u = q.front();
	        ans.push_back(u);
	        q.pop();
	        
	        for(int v: adj[u]) {
	            if(!visited[v]) {
	                q.push(v);
	                visited[v] = true;
	            }
	        }
	    }
	    return ans;
	}
	
	vector<int>bfsOfGraph(int V, vector<int> adj[])
	{
	    bool visited[V] = {false};
	    return bfs(adj, 0, visited);
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    // 		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}
