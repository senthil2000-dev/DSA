#include<bits/stdc++.h>
using namespace std;
#define f(i,n) for(int i=0; i<=n; i++)

string longestPalindrome(string s) {
    int n = s.length();
    string res= "";
    if (!n) return res;
    int dp[n+1][n+1];
    f(i, n) dp[0][i] = 1, dp[1][i] = 1;
    dp[1][0] = 0;
    int end=1, length=1;
    for(int i=2; i<=n; i++) {
        for(int j=i; j<=n; j++) {
            if(s[j-1]==s[j-i] && dp[i-2][j-1])
                dp[i][j] = 1, end = j, length = i;
            else
                dp[i][j] = 0;
        }
    }
    return s.substr(end-length, length);
}

int main() {
    string s;
    cin>>s;
    cout<<longestPalindrome(s);    
}
