#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    void dfs(vector<vector<int>>& grid, vector<vector<bool>> &visited, pair<int, int> loc, int m, int n, int &count) {
        int p = loc.first;
        int q = loc.second;
        int dx[3] = {0, -1, 1};
        int dy[3] = {0, -1, 1};
        visited[p][q] = true;
        count++;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(i || j) {
                    int x = p + dx[i];
                    int y = q + dy[j];
                    if(x<m && x>=0 && y<n && y>=0 && !visited[x][y] && grid[x][y]!=0) {
                        dfs(grid, visited, {x, y}, m, n, count);
                    }
                }
            }
        }
    }
    
    int findMaxArea(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int res = 0, count;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(!visited[i][j] && grid[i][j] == 1) {
                    count = 0;
                    dfs(grid, visited, {i, j}, m, n, count); 
                    res = max(res, count);
                }  
            }
        }
        return res;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}
