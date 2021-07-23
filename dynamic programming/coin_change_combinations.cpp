#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=1; i<=n; i++)

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    int dp[amount+1][n+1];
    dp[0][0]=1;
    f(i, n) dp[0][i] = 1;
    f(i, amount) dp[i][0] = 0;
    f(i, amount) {
        f(j, n) {
            dp[i][j] = dp[i][j-1];
            if(coins[j-1]<=i)
                dp[i][j] += dp[i-coins[j-1]][j];
        }
    }
    return dp[amount][n];
}

int main() {
    vector<int> coins{1,2,5};
    int sum = 5;
    cout<<change(sum, coins);
}
