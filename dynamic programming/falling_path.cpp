#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0;i<n;i++)

int minFallingPathSum(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    int dp[m][n];
    f(i, n) {
        dp[m-1][i] = matrix[m-1][i];
    }
    for(int i = m-2; i>=0; i--) {
        f(j, n) {
            dp[i][j] = matrix[i][j];
            int toadd = dp[i+1][j];
            if(j-1>=0) toadd = min(toadd, dp[i+1][j-1]);
            if(j+1<n) toadd = min(toadd, dp[i+1][j+1]);
            dp[i][j] += toadd;
        }
    }
    
    return *min_element(dp[0], dp[0]+n);
}

int main() {
    vector<vector<int>> matrix {{2,1,3},
                                {6,5,4},
                                {7,8,9}};
    cout<<minFallingPathSum(matrix)<<endl;
}
