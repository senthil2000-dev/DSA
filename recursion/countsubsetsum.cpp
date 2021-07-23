#include<bits/stdc++.h>
using namespace std;

int count(int arr[], int n, int sum) {
    if(n==0)
        return sum == 0? 1 : 0;
    return count(arr, n-1, sum) + count(arr, n-1, sum - arr[n-1]);
}

int main() {
    int arr[] = {10, 20, 15, 5};
    cout<<count(arr, 4, 25)<<endl;   
}
