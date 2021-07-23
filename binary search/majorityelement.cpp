#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int ans = nums[0], count = 1;
    int n = nums.size();
    for(int i=1; i<n; i++) {
        if(nums[i] == ans) count++;
        else count--;
        if(count == 0) {
            count = 1;
            ans = nums[i];
        } 
    }

    count = 0;
    for(int i=0; i<n; i++) {
        if(nums[i] == ans) count++;
    }
    if(count<=n/2) ans = -1;
    return ans;
}

int main() {
    vector<int> arr {2,2,1,1,1,2,2};
    cout<<majorityElement(arr)<<endl;
}
