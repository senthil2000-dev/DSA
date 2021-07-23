#include<bits/stdc++.h>
using namespace std;

int matrixMultiplication(int n, int arr[]) {
    int dp[n][n];
    for(int i=0; i+1<n; i++) dp[i][i+1] = 0;
    for(int gap = 2; gap<n; gap++) {
        for(int i=0; i+gap<n; i++) {
            int j = i+gap;
            dp[i][j] = INT_MAX;
            for(int k=i+1; k<j; k++) {
              dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j]);
            }
        }
    }
    return dp[0][n-1]; 
}

int main() {
    int N = 5;
    int arr[] = {40, 20, 30, 10, 30};
    cout<<matrixMultiplication(N, arr)<<endl;
}
