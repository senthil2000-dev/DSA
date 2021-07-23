#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)
#define INF INT_MAX

int minPathSum(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int dp[m+1][n+1];
    f(i, m+1) {
        dp[i][n] = INF;
    }
    f(i, n+1) {
        dp[m][i] = INF;
    }
    dp[m][n-1]=dp[m-1][n]=0;
    for(int i = m-1; i>=0; i--) {
        for(int j=n-1; j>=0; j--) {
            dp[i][j] = grid[i][j] + min(dp[i][j+1], dp[i+1][j]);
        }
    }
    
    return dp[0][0];
}

int main() {
    vector<vector<int>> grid {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};
    cout<<minPathSum(grid)<<endl;
}
