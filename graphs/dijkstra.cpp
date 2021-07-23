#include<bits/stdc++.h>
using namespace std;


class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<int> dist(V, INT_MAX);
        dist[S] = 0;
        pq.push({dist[S], S});
        bool confirmed[V] = {false};
        while(!pq.empty()) {
            int u = pq.top()[1];
            pq.pop();
            if(confirmed[u]) continue;
            confirmed[u] = true;
            for(auto ver: adj[u]) {
                int v = ver[0];
                int w = ver[1];
                if(!confirmed[v] && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }
};

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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }
    return 0;
}
