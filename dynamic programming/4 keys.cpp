#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    long long int optimalKeys(int N) {
        long long dp[N+1];
        // for 1 to 6 just printing i A's is the way to get maximum A's
        for(int i=1; i<=6 && i<=N; i++) dp[i] = i;
        for(int i=7; i<=N; i++) {
            dp[i] = INT_MIN;
            for(int j=1; j<=i-3; j++) { //each dp[j] ends with a series or one ctrl V
                dp[i] = max(dp[i], (i-1-j)*dp[j]); //(i-2-j) copies + 1 origianl of dp[j] A's are produced (minimum 1 copy for numbers after 7)
            }
        }
        return dp[N];
    }
};
