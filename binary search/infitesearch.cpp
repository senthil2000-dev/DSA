#include<bits/stdc++.h>
using namespace std;

int bsearch(int arr[], int l, int h, int x) {
    while(l<=h) {
        int mid = l + (h - l)/2;
        if(arr[mid] == x) return mid;
        else if(arr[mid]>x) h = mid-1;
        else l = mid+1;
    }
    return -1;
}

int searchInSorted(int arr[], int n, int x) { 
    if(x == arr[0]) return 0;
    int i=1;
    while(arr[i]<x) i*=2;
    if(arr[i] == x) return i;
    return bsearch(arr, i/2, i-1, x);
}

int main() {
    int arr[] = {1,3,4,5,6};
    int arr2[] = {-1,0,3,5,9,12};
    // cout<<searchInSorted(arr2, 6, 12)<<endl;
    // cout<<searchInSorted(arr, 5, 6)<<endl;
    cout<<searchInSorted(arr, 5, -5)<<endl;
}

// test with leetcode normal bsearch
// int bsearch(vector<int>& arr, int l, int h, int x) {
//     while(l<=h) {
//         int mid = l + (h - l)/2;
//         if(arr[mid] == x) return mid;
//         else if(arr[mid]>x) h = mid-1;
//         else l = mid+1;
//     }
//     return -1;
// }

// int search(vector<int>& arr, int x) {
//     long long n = arr.size();
//     if(x == arr[0]) return 0;
//     int i=1;
//     while(i<n && arr[i]<x) i*=2;
//     if(i<n && arr[i] == x) return i;
//     if(i>=n)  return bsearch(arr, i/2, n-1, x);
//     return bsearch(arr, i/2, i-1, x);
// }
