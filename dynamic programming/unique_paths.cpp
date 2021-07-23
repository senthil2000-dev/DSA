#include<bits/stdc++.h>
using namespace std;
#define f(i, n) for(int i=0; i< n; i++)
#define f1(i, n) for(int i=n; i>=0; i--)

int uniquePaths(int m, int n) {
    int dp[m][n];
    f(i, m) 
        dp[i][n-1] = 1;
    f(i, n)
        dp[m-1][i] = 1;
    for(int i=m-2; i>=0; i--) {
        for(int j=n-2; j>=0; j--) {
            dp[i][j] = dp[i+1][j] + dp[i][j+1];
        }
    }
    return dp[0][0];
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    long long dp[m][n];
    dp[m-1][n-1] = obstacleGrid[m-1][n-1] ^ 1;
    f1(i, m-2) {
        if(obstacleGrid[i][n-1] != 1)
            dp[i][n-1] = dp[i+1][n-1];
        else
            dp[i][n-1] = 0;
    }
    f1(i, n-2) {
        if(obstacleGrid[m-1][i] != 1)
            dp[m-1][i] = dp[m-1][i+1];
        else
            dp[m-1][i] = 0;
    }
    for(int i=m-2; i>=0; i--) {
        for(int j=n-2; j>=0; j--) {
            dp[i][j] = obstacleGrid[i][j] ? 0 : dp[i+1][j] + dp[i][j+1];
        }
    }
    return dp[0][0];
}

int main() {
    // int m, n;
    // cin>>m>>n;
    // cout<<uniquePaths(m, n)<<endl;
    vector<vector<int>> grid {
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    };
    cout<<uniquePathsWithObstacles(grid)<<endl;
}
