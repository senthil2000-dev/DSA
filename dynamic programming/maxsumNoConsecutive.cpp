#include<bits/stdc++.h>
using namespace std;

int FindMaxSum(int arr[], int n) {
    int dp[n+1];
    dp[1] = arr[0];
    dp[2] = max(arr[0], arr[1]);
    for(int i=3; i<=n; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + arr[i-1]);
    }
    return dp[n];
}

int lessspace(int arr[], int n) {
    int prev_prev = 0;
    int prev = arr[0];
    int res = prev;
    for(int i=2; i<=n; i++) {
        res = max(prev, prev_prev + arr[i-1]);
        prev_prev = prev;
        prev = res;
    }
    return res;
}

int main() {
    int n = 6;
    int a[] = {5,5,10,100,10,5};
    cout<<FindMaxSum(a, n)<<endl;
    cout<<lessspace(a, n)<<endl;
}
