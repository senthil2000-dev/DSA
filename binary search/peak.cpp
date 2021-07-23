#include<bits/stdc++.h>
using namespace std;

int peakElement(int arr[], int n) {
    int l=0, h=n-1, mid;
    while(l<=h) {
        mid = l+(h-l)/2;
        if((mid==0 || arr[mid-1]<=arr[mid]) && (mid==n-1 || arr[mid]>=arr[mid+1]))
            return mid;
        if(mid>0 && arr[mid-1]>=arr[mid])
            h = mid-1;
        else
            l = mid+1;
    }
    return -1;
}

int main() {
    int arr[] = {1, 4 ,3, 6, 1};
    cout<<peakElement(arr, 5)<<endl;
}
