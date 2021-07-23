#include<bits/stdc++.h>
using namespace std;

int bsearch(int arr[], int l, int h, int x) {
    if(l>h) return -1;
    int mid = l + (h - l)/2;
    if(arr[mid] == x) return mid;
    else if(arr[mid]>x) return bsearch(arr, l, mid-1, x);
    else return bsearch(arr, mid+1, h, x);
}

//for arrays
int search(int arr[], int n, int x) {
    int l=0, h=n-1;
    while(l<=h) {
       int mid = l + (h - l)/2;
       if(arr[mid] == x) return mid;
       else if(arr[mid]>x) h = mid-1;
       else l = mid+1;
    }
    return -1;
}

int search2(int arr[], int n, int x) {
    int ind = lower_bound(arr, arr+n, x) - arr;
    return (ind<n && arr[ind] == x) ? ind: -1;
}

//for vectors
int search(vector<int>& arr, int x) {
    int ind = lower_bound(arr.begin(), arr.end(), x)-arr.begin();
    return (ind<arr.size() && arr[ind] == x) ? ind: -1;
}

//check if present
int searchInSorted(int arr[], int n, int x) 
{ 
    return binary_search(arr, arr+n, x)? 1 :-1;
}

int main() {
    int arr[] = {1,2,3,4};
    cout<<bsearch(arr, 0, 3, 5)<<endl;
    cout<<search(arr, 4, 3)<<endl;
    cout<<search2(arr, 4, 3)<<endl;
    cout<<searchInSorted(arr, 4, 3)<<endl;
}


