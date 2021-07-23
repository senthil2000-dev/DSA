#include<bits/stdc++.h>
using namespace std;

int coinChange(int coins[], int amount) {
    int n = 1;
    int dp[amount+1];
    memset(dp, -1, sizeof(dp));
    dp[0] = 0;
    for(int i=1; i<=amount; i++) {
        for(int j=0; j<n; j++) {
            if(coins[j] <= i) {
                if(dp[i - coins[j]]!=-1)
                    dp[i] = dp[i]!=-1 ? min(dp[i], dp[i - coins[j]] + 1): dp[i - coins[j]] + 1;
            }
        }
    }
    return dp[amount];
}

int main() {
    int coins[]={3, 2, 3};
    int sum = 6;
    cout<<coinChange(coins, sum);
}
