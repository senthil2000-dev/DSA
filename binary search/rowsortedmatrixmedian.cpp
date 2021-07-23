#include<bits/stdc++.h>
using namespace std;

int rowMedian(vector<vector<int>>& arr) {
    int n = arr.size();
    int m = arr[0].size();
    int l = arr[0][0], r = arr[0][m-1];
    for(int i=1; i<n; i++) {
        l = min(l, arr[i][0]);
        r = max(r, arr[i][m-1]);
    }
    int medPos = (m*n + 1)/2, mid, pos;
    while(l<r) {
        mid = l + (r-l)/2;
        pos = 0;
        for(int i=0; i<n; i++)
            pos += upper_bound(arr[i].begin(), arr[i].end(), mid) - arr[i].begin();
        if(pos<medPos)
            l = mid+1;
        else
            r = mid;
    }
    return r;
}

int main() {
    vector<vector<int>> matrix {{1, 4, 5},
                                {2, 6, 9},
                                {3, 6, 10}};
    cout<<rowMedian(matrix)<<endl;
}
