#include<bits/stdc++.h>
using namespace std;

long long maximumAmount(int arr[], int n) {
    long long dp[n][n];
    for(int i=0; i+1<n; i++) {
       dp[i][i+1]=max(arr[i], arr[i+1]);
    }
    for(int gap=3; gap<n; gap+=2) {
        for(int i=0; i+gap<n; i++) {
            int j = i+gap;
            dp[i][j] = max(
                arr[i] + min(dp[i+2][j],dp[i+1][j-1]),
                arr[j] + min(dp[i+1][j-1],dp[i][j-2])
            );
        }
    }
    return dp[0][n-1];
}

int main() {
    int arr[] = {5,3,7,10}; int n=4;
    cout<<maximumAmount(arr, n);
}
