#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	struct comparator {
	    bool operator() (const vector<int> &a, const vector<int> &b) {
	        return a[1]>b[1];
	    }
	};
	
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int key[V], res = 0;
        fill(key, key+V, INT_MAX);
        key[0] = 0;
        bool mSet[V] = {false};
        priority_queue<vector<int>, vector<vector<int>>, comparator> pq;
        pq.push({0, 0});
        while(!pq.empty()) {
            int min = pq.top()[0];
            pq.pop();
            if(mSet[min] == true)
                continue;
            mSet[min] = true;
            res += key[min];
            for(auto v: adj[min]) {
                if(!mSet[v[0]] && key[v[0]] > v[1]) {
                    key[v[0]] = v[1];
                    pq.push({v[0], key[v[0]]});
                }
            }
        }
        return res;
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
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
