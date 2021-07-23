#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
	//Function to return a list containing the DFS traversal of the graph.
	vector<int>dfs(vector<int> adj[], int src, bool visited[], vector<int> &ans) {
	    ans.push_back(src);
	    visited[src] = true;
	    for(int v: adj[src]) {
	        if(!visited[v])
	            dfs(adj, v, visited, ans);
	    }
	    return ans;
	}
	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int> ans;
	    bool visited[V] = {false};
	    return dfs(adj, 0, visited, ans);
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
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}
