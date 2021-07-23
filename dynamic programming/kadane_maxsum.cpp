#include<bits/stdc++.h>
using namespace std;
#define f(i, n) for(int i=0; i<n; i++)

int kadane(int arr[], int n) {
    int dp[n+1] = {0};
    for(int i=1; i<=n; i++) {
        dp[i] = max(dp[i-1], 0) + arr[i-1];
    }

    return *max_element(dp, dp+n+1);
}

int main() {
    int n;
    cin>>n;
    int arr[n];
    f(i, n) cin>>arr[i];
    cout<<kadane(arr, n)<<endl; 
}
