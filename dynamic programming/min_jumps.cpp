#include<bits/stdc++.h>
using namespace std;
#define f0(i, n) for(int i=0; i<n; i++)
#define f1(i, n) for(int i=1; i<n; i++)

int jump(vector<int>& nums) {
    int n = nums.size();
    int dp[n];
    f0(i, n) dp[i] = INT_MAX;
    dp[0] = 0;
    f1(i, n) {
        for(int j=0; j<i; j++) {
            if(nums[j]+j>=i && dp[j]!=INT_MAX) {
                dp[i] = min(dp[i], dp[j]+1);
            }
        }
    }
    return dp[n-1];
}

int main() {
    vector<int> nums {2,3,1,1,4};
    cout<<jump(nums)<<endl;    
}
