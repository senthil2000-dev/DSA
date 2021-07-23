#include <bits/stdc++.h>
using namespace std;

//2 sum
vector<int> twoSum(vector<int>& arr, int target) {
    int i=0, j=arr.size() - 1;
    while(i<j) {
        if(arr[i]+arr[j] == target) return {i+1, j+1};
        else if(arr[i]+arr[j]>target) j--;
        else i++;
    }
    return {-1, -1};
}

//3 sum(all unique solutions with sum 0)
vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> s;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for(int k=0; k<n; k++) {
        int i=k+1, j=n-1;
        while(i<j) {
            if(nums[i]+nums[j]+nums[k] == 0) {
                s.insert({nums[i], nums[j], nums[k]});
                i++; j--;
            }
            else if(nums[i]+nums[j]+nums[k]>0) j--;
            else i++;
        }
    }
    vector<vector<int>> v(s.begin(), s.end());
    return v; 
}

int main() {
    vector<int> arr {-1,0,1,2,-1,-4};
    threeSum(arr);
}
