#include<bits/stdc++.h>
using namespace std;

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

int ceil(int tail[], int l, int r, int key) {
    while(l<r) {
        int m = l + (r-l)/2;
        if(key<=tail[m]) r=m;
        else l=m+1;
    }
    return r;
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

int maxBitonicLessTime(vector<int> &nums) {
    int n = nums.size();
    int tail[n];
    int increasing[n], decreasing[n];
    int length = 1;
    tail[0] = nums[0];
    increasing[0] = 1;
    for(int i=1; i<n; i++) {
        if(nums[i] > tail[length-1]) {
            tail[length++] = nums[i];
            increasing[i] = length;
        }
        else {
            int ceilInd = lower_bound(tail, tail+length, nums[i]) - tail;
            // int ceilInd = ceil(tail, 0, length-1, nums[i]);
            tail[ceilInd] = nums[i];
            increasing[i] = ceilInd+1;
        }
    }
    reverse(nums.begin(), nums.end());
    int tail2[n];
    tail2[0] = nums[0];
    decreasing[0] = 1;
    length = 1;
    for(int i=1; i<n; i++) {
        if(nums[i] > tail2[length-1]) {
            tail2[length++] = nums[i];
            decreasing[i] = length;
        }
        else {
            int ceilInd = lower_bound(tail2, tail2+length, nums[i]) - tail2;
            // int ceilInd = ceil(tail2, 0, length-1, nums[i]);
            tail2[ceilInd] = nums[i];
            decreasing[i] = ceilInd+1;
        }
    }
    reverse(decreasing, decreasing+n);
    int res = increasing[0]+decreasing[0]-1;
    for(int i=1; i<n; i++) 
        res = max(res, increasing[i]+decreasing[i]-1);
    return res;
}

int maxSumIncSeq(vector<int>& nums) {
    int n = nums.size();
    if(!n) return n;
    int dp[n];
    dp[0] = nums[0];
    for(int i=1; i<n; i++) {
        dp[i] = nums[i];
        for(int j=0; j<i; j++) {
            if(nums[j]<nums[i]) {
                dp[i] = max(dp[i], dp[j]+nums[i]);
            }
        }
    }
    return *max_element(dp, dp+n);
}

int longestBitonicSeq(vector<int>& nums) {
    int n = nums.size();
    if(!n) return n;
    int dp[n], dp2[n];
    dp[0] = 1;
    for(int i=1; i<n; i++) {
        dp[i] = 1;
        for(int j=0; j<i; j++) {
            if(nums[j]<nums[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    dp2[n-1] = 1;
    for(int i=n-2; i>=0; i--) {
        dp2[i] = 1;
        for(int j=n-1; j>i; j--) {
            if(nums[j]<nums[i]) {
                dp2[i] = max(dp2[i], dp2[j]+1);
            }
        }
    }
    int res = dp[0]+dp2[0]-1;
    for(int i=1; i<n; i++) {
        res = max(res, dp[i]+dp2[i]-1);
    }
    return res;
}

int main() {
    vector<int> nums {9, 29, 6};
    int n =nums.size();
    int lis = lengthOfLIS2(nums);
    cout<<"Minimum of deletions "<<(n-lis)<<endl;
    cout<<maxSumIncSeq(nums)<<endl;
    cout<<maxBitonicLessTime(nums)<<endl;
}
