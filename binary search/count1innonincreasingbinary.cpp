#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int countOnes(int arr[], int n)
    {
        
        int l=0, h=n-1;
        int mid;
        while(l<=h) {
            mid = l+(h-l)/2;
            if(arr[mid] == 0)
                h = mid-1;
            else {
                if(mid==n-1 || arr[mid]!=arr[mid+1]) return mid+1;
                else l = mid+1;
            }
        }
        return 0;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int *arr = new int[n]; 
        for(int i = 0; i < n; i++)
            cin>>arr[i];
            
        Solution ob;
        cout <<ob.countOnes(arr, n)<<endl;
    }
    return 0;
}
