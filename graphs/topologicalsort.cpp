#include <bits/stdc++.h>
using namespace std;


class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(vector<int> adj[], int u, stack<int> &st, bool visited[]) {
	    visited[u] = true;
	    for(int v: adj[u]) {
	        if(!visited[v])
	            dfs(adj, v, st, visited);
	    }
	    st.push(u);
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) 
	{   vector<int> top;
	    stack<int> st;
	    bool visited[V] = {false};
	    for(int i=0; i<V; i++) {
	        if(!visited[i])
	            dfs(adj, i, st, visited);
	    }
	    while(!st.empty()) {
	        top.push_back(st.top());
	        st.pop();
	    }
	    return top;
	}
};

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
