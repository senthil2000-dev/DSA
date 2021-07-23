#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<=n; i++)
#define f1(i,n) for(int i=1; i<=n; i++)

int minDistance(string word1, string word2) {
    int m = word1.length();
    int n = word2.length();
    int dp[m+1][n+1];
    f(i, n) dp[0][i] = i;
    f(i, m) dp[i][0] = i;
    f1(i, m) {
        f1(j, n) {
            if(word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1]));
        }
    }
    return dp[m][n];
}

int main() {
    string word1 = "horse", word2 = "ros";
    cout<<minDistance(word1, word2)<<endl;
}
