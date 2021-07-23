#include<bits/stdc++.h>
using namespace std;
#define f(i, n) for(int i=0; i<n; i++)

int longestCommonSubsequence(string text1, string text2, bool printLcs = true) {
    int m = text1.length(), n = text2.length();
    int dp[m+1][n+1];
    f(i, n+1) dp[0][i] = 0;
    f(j, m+1) dp[j][0] = 0;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(text1[i-1] == text2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int lcs = dp[m][n];
    char lcsStr[lcs+1];
    lcsStr[lcs--] = '\0';
    int i=m, j=n;
    while(i!=0 && j!=0) {
        if(text1[i-1] == text2[j-1]) {
            lcsStr[lcs--] = text2[j-1];
            i--;
            j--;
        }
        else {
            if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
    }
    if(printLcs)
        cout<<lcsStr<<endl;
    return dp[m][n];
}

void insertionsdeletions(int lcs, int m, int n) {
    cout<<(m-lcs)<<" deletions & "<<(n - lcs)<<" insertions"<<endl;
}

int longestPalindromicsequence(string s2) {
    string s1 = s2;
    reverse(s2.begin(), s2.end());
    return longestCommonSubsequence(s1, s2, false);
}

int longestRepeatingSequence(string text1) {
    string text2 = text1;
    int m = text1.length(), n = text2.length();
    int dp[m+1][n+1];
    f(i, n+1) dp[0][i] = 0;
    f(j, m+1) dp[j][0] = 0;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(text1[i-1] == text2[j-1] && i!=j)
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];
}

string superseq(string text1, string text2) {
    int m = text1.length(), n = text2.length();
    int dp[m+1][n+1];
    f(i, n+1) dp[0][i] = 0;
    f(j, m+1) dp[j][0] = 0;
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(text1[i-1] == text2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    int lcs = dp[m][n];
    char lcsStr[lcs];
    int i=m, j=n;
    while(i!=0 && j!=0) {
        if(text1[i-1] == text2[j-1]) {
            lcsStr[--lcs] = text2[j-1];
            i--;
            j--;
        }
        else {
            if(dp[i-1][j]>dp[i][j-1]) i--;
            else j--;
        }
    }
    string sup = "";
    // abcdfea answer
    int p1=0, p2=0;
    for(char c: lcsStr) {
        while(text1[p1]!=c)
            sup+=text1[p1++];
        while(text2[p2]!=c)
            sup+=text2[p2++];
        sup+=c;
        p1++;p2++;        
    }
    sup+=(text1.substr(p1)+text2.substr(p2));
    return sup;
}

int main() {
    string s1 = "abcde";
    string s2 = "acfea";
    int lcs = longestCommonSubsequence(s1, s2);
    cout<<lcs<<endl;
    insertionsdeletions(lcs, s1.length(), s2.length());
    cout<<longestPalindromicsequence(s2)<<endl;
    string s3="aaaa";
    cout<<longestRepeatingSequence(s3)<<endl;
    cout<<superseq(s1, s2)<<endl;
}
