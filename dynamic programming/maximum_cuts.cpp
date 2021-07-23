#include<bits/stdc++.h>
using namespace std;

int maxCuts(int n, int a, int b, int c) {
    int dp[n+1];
    dp[0] = 0;
    for(int i=1; i<=n; i++) {
        dp[i] = -1;
        if(a<=i) dp[i] = max(dp[i], dp[i-a]);
        if(b<=i) dp[i] = max(dp[i], dp[i-b]);
        if(c<=i) dp[i] = max(dp[i], dp[i-c]);
        if(dp[i]!=-1) dp[i]++;
    }
    return dp[n];
}

int main() {
    int n = 5, a = 2, b = 2, c = 2;
    cout<<maxCuts(n, a, b, c);
}
