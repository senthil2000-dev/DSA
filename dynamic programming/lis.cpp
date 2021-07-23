#include<bits/stdc++.h>
using namespace std;

int ceil(int tail[], int l, int r, int key) {
    while(l<r) {
        int m = l + (r-l)/2;
        if(key<=tail[m]) r=m;
        else l=m+1;
    }
    return r;
}

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if(!n) return n;
    int dp[n];
    dp[0] = 1;
    for(int i=1; i<n; i++) {
        dp[i] = 1;
        for(int j=0; j<i; j++) {
            if(nums[j]<nums[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    return *max_element(dp, dp+n);
}

int lengthOfLIS2(vector<int>& nums) {
    // binary search O(nlogn)
    int n = nums.size();
    int tail[n];
    int length = 1;
    tail[0] = nums[0];
    for(int i=1; i<n; i++) {
        if(nums[i] > tail[length-1]) {
            tail[length++] = nums[i];
        }
        else {
            int ceilInd = lower_bound(tail, tail+length, nums[i]) - tail;
            // int ceilInd = ceil(tail, 0, length-1, nums[i]);
            tail[ceilInd] = nums[i];
        }
    }
    return length;
}

int main() {
    vector<int> nums {4,10,4,3,8,9};
    cout<<lengthOfLIS2(nums);
}
