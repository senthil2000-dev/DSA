#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int n = nums.size();
    int l =0, h=n-1;
    int mid;
    while(l<=h) {
        mid = l+(h-l)/2;
        if(nums[mid] == target) return mid;
        else {
            if(nums[mid]>=nums[l]) {
                if(target>=nums[l] && target<nums[mid])
                    h = mid-1;
                else 
                    l = mid+1;
            }
            else {
                if(target>nums[mid] && target<=nums[h])
                    l = mid+1;
                else 
                    h = mid-1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> arr{3, 1};
    cout<<search(arr, 1)<<endl;
    cout<<search(arr, -5)<<endl;
}
