#include<bits/stdc++.h>
using namespace std;
#define f(i, s, n) for(int i=s; i<=n;i++)

int superEggDrop(int f, int e) {
    long long int dp[f+1][e+1];
    f(i, 1, e)  {
        dp[0][i] = 0;
        dp[1][i] = 1;
    }
    f(i, 2, f) dp[i][1] = i;
    f(i, 2, f) {
        f(j, 2, e) {
            dp[i][j] = INT_MAX;
            f(x, 1, i) {
                dp[i][j] = min(dp[i][j], max(dp[x-1][j-1], dp[i-x][j])+1);
            }
        }
    }
    return dp[f][e];
}

int main() {
    int e=2, f=6;
    cout<<superEggDrop(f, e)<<endl;
}
