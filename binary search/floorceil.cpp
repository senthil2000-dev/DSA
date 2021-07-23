#include<bits/stdc++.h>
using namespace std;

int findFloor(vector<long long> arr, long long n, long long x) {
    int ind = lower_bound(arr.begin(), arr.end(), x)-arr.begin();
    if(arr[ind] == x) return ind;
    return ind-1;
}

int ceilFloor(vector<long long> arr, long long n, long long x) {
    int ind = upper_bound(arr.begin(), arr.end(), x)-arr.begin();
    if(ind!=0 && arr[ind-1] == x) return ind-1;
    if(ind == n) return -1;
    return ind;
}

int findFloor2(vector<long long> arr, long long low, long long high, long long x) {
    long long mid = low+(high-low)/2;
    if(x<arr[low]) return -1;
    if(x>=arr[high]) return high;
    if(arr[mid] == x) return mid;
    else if(arr[mid]<x) {
        if(mid+1<=high && arr[mid+1]>x) return mid;
        return findFloor2(arr, mid+1, high, x);
    }
    else {
        if(mid-1>=low && arr[mid-1]<=x) return mid-1;
        return findFloor2(arr, low, mid-1, x); 
    }
}

int ceil(vector<long long> arr, long long low, long long high, long long x) {
    long long mid = low+(high-low)/2;
    if(x>arr[high]) return -1;
    if(x<=arr[low]) return low;
    if(arr[mid] == x) return mid;
    else if(arr[mid]>x) {
        if(mid-1>=low && arr[mid-1]<x) return mid;
        return ceil(arr, low, mid-1, x);
    }
    else {
        if(mid+1<=high && arr[mid+1]>=x) return mid+1;
        return ceil(arr, mid+1, high, x);
    }
}

int main() {
    vector<long long> arr{1,2,3,5};
    cout<<findFloor(arr, 4, 0)<<endl;
    cout<<ceilFloor(arr, 4, 3)<<endl;
    cout<<findFloor2(arr, 0, 3, 4)<<endl;
    cout<<ceil(arr, 0, 3, 4)<<endl;
}
