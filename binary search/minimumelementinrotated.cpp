#include<bits/stdc++.h>
using namespace std;

int minNumber(int arr[], int low, int high) {
    int mid;
    while(low<high) {
        mid = low + (high-low)/2;
        //duplicate condition
        if(arr[mid] == arr[high])
            high--;
        else if(arr[mid]>arr[high]) //right half unsorted
            low = mid+1;
        else
            high = mid;
    }
    return arr[low];
}

int maxNumber(int arr[], int low, int high) {
    int mid;
    while(low<high) {
        mid = low + (high-low)/2;
        //duplicate condition
        if(low == mid && arr[low]>arr[high]) return arr[low];
        if(arr[mid] == arr[low])
            low++;
        else if(arr[low]>arr[mid]) //left half unsorted
            high = mid-1;
        else
            low = mid; //start from greatest in sorted
    }
    
    return arr[low];
}

int main() {
    int arr[] = {6, 5, 6, 6, 6, 6};
    int arr2[] = {5, 6, 5, 5, 5, 5};
    int arr3[] = {5, 7, 1, 2, 3, 4};
    cout<<minNumber(arr, 0, 5)<<endl;
    cout<<maxNumber(arr2, 0, 1)<<endl;
    cout<<maxNumber(arr3, 0, 5)<<endl;
}
