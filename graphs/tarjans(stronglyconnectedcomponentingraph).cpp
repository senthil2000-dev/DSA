#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    void dfs(int u, vector<int> adj[], int low[], int disc[], int &time, stack<int> &st, bool stackMember[], vector<vector<int>> &tar) {
        low[u] = disc[u] = ++time;
        st.push(u);
        stackMember[u] = true;
        for(int v: adj[u]) {
            if(disc[v] == -1) {
                dfs(v, adj, low, disc, time, st, stackMember, tar);
                low[u] = min(low[u], low[v]);
            }
            else if(stackMember[v]) {
                low[u] = min(low[u], disc[v]);
            }
        }
        if(low[u] == disc[u]) {
            vector<int> ve;
            while(st.top() != u) {
                int w = st.top();
                ve.push_back(w);
                st.pop();
                stackMember[w] = false;
            }
            int w = st.top();
            ve.push_back(w);
            st.pop();
            stackMember[w] = false;
            sort(ve.begin(), ve.end());
            tar.push_back(ve);
        }
    }
    
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        int disc[V];
        fill(disc, disc+V, -1);
        int low[V];
        vector<vector<int>> tar;
        stack<int> st;
        bool stackMember[V] = {false};
        int time = 0;
        for(int i=0; i<V; i++) {
            if(disc[i] == -1)
                dfs(i, adj, low, disc, time, st, stackMember, tar);
        }
        sort(tar.begin(), tar.end());
        
        return tar;
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
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}
