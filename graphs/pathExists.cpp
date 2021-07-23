#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find whether a path exists from the source to destination.
    bool dfs(vector<vector<int>>& grid, vector<vector<bool>> &visited, pair<int, int> loc, int m, int n) {
        int p = loc.first;
        int q = loc.second;
        int dx[3] = {0, -1, 1};
        int dy[3] = {0, -1, 1};
        visited[p][q] = true;
        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(abs(dx[i]-dy[j]) == 1) {
                    int x = p + dx[i];
                    int y = q + dy[j];
                    if(x<m && x>=0 && y<n && y>=0 && !visited[x][y] && grid[x][y]!=0) {
                        if(grid[x][y] == 2) return true;
                        if(dfs(grid, visited, {x, y}, m, n)) return true;
                    }
                }
            }
        }
        return false;
    }
    
    bool is_Possible(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    return dfs(grid, visited, {i, j}, m, n);
                }  
            }
        }
        return false;
    }
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
