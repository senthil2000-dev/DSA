#include<bits/stdc++.h>
using namespace std;
#define f(i, s, n) for(int i=s; i<n; i++)

bool isPal(string s) {
    return equal(s.begin(), s.end(), s.rbegin());
}

void palPartition(string s, vector<vector<string>> &ans, int j, vector<string> v) {
    if(j==s.size()) {
        ans.push_back(v);
        v.clear();
        return;
    }

    for(int i=1; j+i-1<s.size(); i++) {
        if(isPal(s.substr(j, i))) { //issafe function
            v.push_back(s.substr(j, i));
            palPartition(s, ans, j+i, v);
            v.pop_back(); //backtrack
        }
    }
}

vector<vector<string>> partition(string s) {
    // backtrack approach-i reprsents length and j represents start
    vector<vector<string>> ans;
    palPartition(s, ans, 0, {});   
    return ans;
}

int minCut(string s) {
    int n = s.length();
    int dp[n][n]; bool pal[n][n];
    f(i, 0, n) dp[i][i] = 0, pal[i][i] = true;
    f(gap, 1, n) {
        for(int i=0; i+gap<n; i++) {
            int j = i+gap;
            if(s[i] == s[j] && (gap == 1 || pal[i+1][j-1])) pal[i][j] = true, dp[i][j]=0;
            else {
                pal[i][j] = false;
                dp[i][j] = INT_MAX;
                f(k, i, j) {
                    dp[i][j] = min(dp[i][j], 1+dp[i][k]+dp[k+1][j]);
                }
            }
        }
    }
    return dp[0][n-1];
}

int optimisedcuts(string s) {
    int n = s.length();
    int dp[n];
    bool pal[n][n];
    for(int i=n-1; i>=0; i--) {
        dp[i]=INT_MAX;
        for(int j=i; j<n; j++) {
            pal[i][j] = (i==j || (s[i]==s[j] && (i==j-1 || pal[i+1][j-1])));
            if(pal[i][j]) 
                dp[i] = (j==n-1)? 0: min(dp[i], 1+dp[j+1]);
        }
    }
    return dp[0];
}

int main() {
    string s = "abcbafef";
    cout<<optimisedcuts(s)<<endl;
    cout<<isPal(s)<<endl;
    vector<vector<string>> v = partition(s);
    f(i, 0, v.size()) {
        f(j, 0, v[i].size()) {
            cout<<v[i][j]<<' ';
        }
        cout<<endl;
    }
}
