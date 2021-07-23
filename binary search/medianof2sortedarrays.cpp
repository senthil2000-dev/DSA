#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n1 = nums1.size();
    int n2 = nums2.size();
    if(n1>n2) {
        nums1.swap(nums2);
        swap(n1, n2); 
    }
    int l=0, r=n1, i1, i2;
    while(l<=r) {
        i1 = l + (r-l)/2;
        i2 = (n1+n2+1)/2 - i1;
        int min1 = i1==n1? INT_MAX : nums1[i1];
        int max1 = i1==0? INT_MIN : nums1[i1-1];
        int min2 = i2==n2? INT_MAX : nums2[i2];
        int max2 = i2==0? INT_MIN : nums2[i2-1];
        if(min1 >= max2 && min2 >= max1) {
            if((n1+n2)%2)
                return max(max1, max2);
            else
                return (double(max(max1, max2)) + min(min1, min2))/2;
        }
        else if(max2>min1)
            l = i1+1;
        else
            r = i1-1;
    }
    return -1;
}

int main() {
    vector<int> arr1 {}, arr2 {2};
    cout<<findMedianSortedArrays(arr1, arr2)<<endl;
}
