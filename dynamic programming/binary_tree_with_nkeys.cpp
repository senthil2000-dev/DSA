#include<bits/stdc++.h>
using namespace std; 
#define mod 1000000007

int numTrees(int n) {
    int dp[n+1];
    dp[0] = 1;
    for(int i=1; i<=n; i++) {
        dp[i] = 0;
        for(int j=0; j<i; j++) {
            (dp[i] += (dp[j]*dp[i-1-j])%mod)%=mod;
        }
    }
    return dp[n];
}

int main() {
    int n = 384;
    cout<<numTrees(n);
}
