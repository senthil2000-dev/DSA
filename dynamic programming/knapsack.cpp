#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<=n; i++)
#define f1(i,n) for(int i=1; i<=n; i++)

int knapSack(int w, int wt[], int val[], int n) { 
    int dp[n+1][w+1];
    f(i, n) dp[i][0] = 0;
    f(i, w) dp[0][i] = 0;
    f1(i, n) {
        f1(j, w) {
            if(wt[i-1]>j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j-wt[i-1]]);
        }
    }
    return dp[n][w];
}

int main() {
    int N = 3;
    int W = 4;
    int values[] = {1,2,3};
    int weight[] = {4,5,1};
    cout<<knapSack(W, weight, values, N)<<endl;
}
