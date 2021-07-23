#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> dist(n, INT_MAX);
	    dist[0] = 0;
	    for(int count = 0; count<n-1; count++) {
	        for(auto edge: edges) {
	            int u = edge[0];
	            int v = edge[1];
	            int w = edge[2];
	            if(dist[u]!=INT_MAX && dist[v] > dist[u] + w)
	                dist[v] = dist[u] + w;
	        }
	    }
	    for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if(dist[u]!=INT_MAX && dist[v] > dist[u] + w) 
                return 1;
        }
        return 0;
	}
};

int main() {
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}
