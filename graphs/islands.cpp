#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> ipair;

void dfs(vector<vector<int>>& grid, vector<vector<bool>> &visited, ipair loc, int m, int n) {
    int p = loc.first;
    int q = loc.second;
    int dx[3] = {0, -1, 1};
    int dy[3] = {0, -1, 1};
    visited[p][q] = true;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(i || j) {
                int x = p + dx[i];
                int y = q + dy[j];
                if(x<m && x>=0 && y<n && y>=0 && !visited[x][y] && grid[x][y]!=0) {
                    dfs(grid, visited, {x, y}, m, n);
                }
            }
        }
    }
}

int numIslands(vector<vector<int>>& grid) 
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    int count = 0;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(!visited[i][j] && grid[i][j] == 1) {
                dfs(grid, visited, {i, j}, m, n); 
                count++;
            }  
        }
    }
    return count;
}


int main() {
    vector<vector<int>> grid {
        {0,1,1,1,0,0,0},
        {0,0,1,1,0,1,0}
    };
    cout<<numIslands(grid);
}
