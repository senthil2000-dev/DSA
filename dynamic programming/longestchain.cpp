#include<bits/stdc++.h>
using namespace std;

//optional
bool compare(const vector<int> &v1, const vector<int> &v2) {
    if(v2[0]!=v1[0])
        return v2[0]>v1[0];
    return v2[1]>v1[1];
}

int findLongestChain(vector<vector<int>>& pairs) {
    int n = pairs.size();
    if(!n) return n;
    sort(pairs.begin(), pairs.end());
    int dp[n];
    dp[0] = 1;
    for(int i=1; i<n; i++) {
        dp[i] = 1;
        for(int j=0; j<i; j++) {
            if(pairs[i][0]>pairs[j][1])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    return *max_element(dp, dp+n);
}

int main() {
    vector<vector<int>> v{
        {1, 2},
        {2, 3},
        {3, 4}
    };
    cout<<findLongestChain(v);
}
