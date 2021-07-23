#include<bits/stdc++.h>
using namespace std;

int getCeil(int arr[], int n, int x) {
    int l=0, h=n-1;
    int mid;
    int ceil=-1;
    while(l<=h) {
        mid = l+(h-l)/2;
        if(arr[mid] == x) return mid;
        else if(arr[mid]>x) {
            ceil = mid;
            h=mid-1;
        }
        else l = mid+1;
    }
    return ceil;
}

int getFloor(int arr[], int n, int x) {
    int l=0, h=n-1;
    int mid;
    int floor=-1;
    while(l<=h) {
        mid = l+(h-l)/2;
        if(arr[mid] == x) return mid;
        else if(arr[mid]<x) {
            floor = mid;
            l = mid+1;
        }
        else h=mid-1;
    }
    return floor;
}
 
int main(void)
{
    int arr[] = { 1, 4, 6, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    for (int i = 0; i <= 10; i++)
    {
        cout<<"Number "<<i<<" —> ";
        cout<<"ceil is "<<getCeil(arr, n, i);
        cout<<" floor is "<<getFloor(arr, n, i)<<endl;
    }
 
    return 0;
}
