
#include<bits/stdc++.h>
using namespace std;

vector<int> find(int a[], int n , int x );
vector<int> find2(int arr[], int n , int x )
{
    int lo = lower_bound(arr, arr+n, x) - arr;
    if(lo>=n || arr[lo] != x) return {-1, -1};
    int up = upper_bound(arr, arr+n, x) - arr;
    return {lo, up-1};
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}


// } Driver Code Ends

vector<int> find(int arr[], int n , int x )
{
    int l=0, h=n-1;
    vector<int> v;
    while(l<=h) {
       int mid = l + (h - l)/2;
       if(arr[mid]>x) h = mid-1;
       else if(arr[mid]<x) l = mid+1;
       else {
           if(mid==0 || arr[mid-1]!=arr[mid]) {v.push_back(mid); break; }
           else h=mid-1;
       }
    }
    if(v.size() == 0) return {-1, -1};
    l=0, h=n-1;
    while(l<=h) {
       int mid = l + (h - l)/2;
       if(arr[mid]>x) h = mid-1;
       else if(arr[mid]<x) l = mid+1;
       else {
           if(mid==n-1 || arr[mid+1]!=arr[mid]) {v.push_back(mid); break;}
           else l=mid+1;
       }
    }
    return v;
}
