#include<bits/stdc++.h>
using namespace std;

bool feasible(int arr[], int n, int k, int res) {
    int sum = 0, req = 1;
    for(int i=0; i<n; i++) {
        if(sum+arr[i]<=res)
            sum+=arr[i];
        else {
            sum=arr[i];
            req++;
        }
    }
    return (k>=req);
}

//mid is no of pages one student has to read at max for which we are searching for min
int findPages(int arr[], int n, int k) {
    if(n<k) return -1; //valid assignment not possible as each student shud be alloted atleast one book
    int l = *max_element(arr, arr+n);
    int r = accumulate(arr, arr+n, 0);
    int mid, res = -1;
    while(l<=r) {
        mid = l+(r-l)/2;
        if(feasible(arr, n, k, mid)) {
            res = mid;
            r = mid - 1;
        }
        else
            l = mid+1;
    }
    return res;
}

int main() {
    int arr[] = {12,34,67,90};
    cout<<findPages(arr, 4, 2)<<endl;
}
