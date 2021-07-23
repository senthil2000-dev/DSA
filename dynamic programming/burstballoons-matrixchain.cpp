#include<bits/stdc++.h>
using namespace std;

int maxCoins(vector<int>& arr) {
    arr.insert(arr.begin(), 1);
    arr.insert(arr.end(), 1);
    int n = arr.size();
    int dp[n][n];
    for(int i=0; i+1<n; i++) dp[i][i+1] = 0;
    for(int gap = 2; gap<n; gap++) {
        for(int i=0; i+gap<n; i++) {
            int j = i+gap;
            dp[i][j] = INT_MIN;
            for(int k=i+1; k<j; k++) {
              dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + arr[i]*arr[k]*arr[j]);
            }
        }
    }
    return dp[0][n-1];
}

int main() {
    int N = 6;
    vector<int> v{3,1,5,8};
    cout<<maxCoins(v)<<endl;
}
