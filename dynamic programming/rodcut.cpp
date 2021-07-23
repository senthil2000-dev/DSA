#include<bits/stdc++.h>
using namespace std;

int cutRod(int price[], int n) {
    int dp[n+1];
    dp[0] = 0;
    for(int i=1; i<=n; i++) {
        dp[i] = INT_MIN;
        for(int j=1; j<=i; j++) {
            dp[i] = max(dp[i], price[j-1] + dp[i-j]);
        }
    }
    return dp[n];
}

int main() {
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int n = sizeof(price)/sizeof(price[0]);
    cout<<cutRod(price, n);
}
