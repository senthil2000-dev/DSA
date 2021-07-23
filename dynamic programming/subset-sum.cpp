#include<bits/stdc++.h>
using namespace std;

int isSubsetSum(int set[], int n, int sum) {
    int dp[n+1][sum+1];
    dp[0][0]=1;
    for(int i=1; i<=sum; i++) dp[0][i] = 0;
    for(int i=1; i<=n; i++) dp[i][0] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=sum; j++) {
            if(set[i-1]>j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j] + dp[i-1][j-set[i-1]];
        }
    }
    return dp[n][sum];
}

int isPossible(int set[], int n, int sum) {
    int dp[sum+1] = {0};
    dp[0] = 1;
    for(int i=0; i<n; i++) {
        for(int j=sum; j>=set[i]; j--) {
            if(dp[j-set[i]]!=0)
                dp[j] += 1;
        }
    }
    return dp[sum];
}

int main() {
    int set[] = { 3, 10, 4, 12, 5, 2};
    int sum = 12;
    int n = sizeof(set) / sizeof(set[0]);
    int no = isPossible(set, n, sum);
    if(no)
        printf("Found %d subsets with given sum", no);
    else
        printf("No subset with given sum");
    return 0;
}

//leetcode variation
// bool canPartition(vector<int>& nums) {
//     int n = nums.size();
//     int sum = 0;
//     for(int i = 0; i<n; i++) {
//         sum+=nums[i];
//     } 
//     if(sum%2) return false;
//     sum /= 2;
//     bool dp[n+1][sum+1];
//     dp[0][0]=true;
//     for(int i=1; i<=sum; i++) dp[0][i] = false;
//     for(int i=1; i<=n; i++) dp[i][0] = true;
//     for(int i=1; i<=n; i++) {
//         for(int j=1; j<=sum; j++) {
//             if(nums[i-1]>j)
//                 dp[i][j] = dp[i-1][j];
//             else
//                 dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
//         }
//     }
//     return dp[n][sum];
// }
