#include<bits/stdc++.h>
using namespace std;

struct Node {
    int v, w;
    Node(int _v, int _w) {
        v = _v;
        w = _w;
    }
};

void addEdge(vector<Node> g[], int u, int v, int w) {
    Node vertex(v, w);
    g[u].push_back(vertex);
}

void dfs(vector<Node> adj[], int u, stack<int> &st, bool visited[]) {
    visited[u] = true;
    for(Node v: adj[u]) {
        if(!visited[v.v])
            dfs(adj, v.v, st, visited);
    }
    st.push(u);
}
	
void shortestPath(int V, vector<Node> adj[], int s) {
    vector<int> top;
    stack<int> st;
    bool visited[V] = {false};
    for(int i=0; i<V; i++) {
        if(!visited[i])
            dfs(adj, i, st, visited);
    }
    
    int dist[V];
    for(int i=0; i<V; i++) {
        dist[i] = INT_MAX;
    }
    dist[s] = 0;

    while(!st.empty()) {
        int top = st.top();
        st.pop();
        for(Node v: adj[top]) {
            //can check for INF outside loop also(better)
            if(dist[top] != INT_MAX && dist[v.v] > v.w + dist[top])
                dist[v.v] = v.w + dist[top]; 
        }
    }

    for(int i=0; i<V; i++) dist[i] == INT_MAX ? cout<<"INF ": cout<<dist[i]<<' ';
}

int main() {
    int V = 6;
	vector<Node> g[V]; 
	addEdge(g, 0, 1, 2); 
	addEdge(g, 0, 4, 1); 
	addEdge(g, 1, 2, 3); 
	addEdge(g, 4, 2, 2); 
	addEdge(g, 4, 5, 4); 
	addEdge(g, 2, 3, 6); 
	addEdge(g, 5, 3, 1);

	int s = 1; 
	cout << "Following are shortest distances from source " << s <<" \n"; 
	shortestPath(V, g, s); 

	return 0; 
}
