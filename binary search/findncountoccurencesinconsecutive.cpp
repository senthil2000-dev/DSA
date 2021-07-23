
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    pair<int, int> findRepeating(int *arr, int n) {
        if(n==1 || n-1 <= arr[n-1]-arr[0]){
            return {-1,-1};
        }
        int l=0, h=n-1;
        while(l<h) {
           int mid = l + (h - l)/2;
           if(arr[n-1] - arr[mid] < n-mid-1) l=mid+1;
           else h=mid;
        }
        return {arr[h], n-(arr[n-1]-arr[0])};
    }
};
int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    Solution obj;
	    pair<int, int> ans = obj.findRepeating(arr,n);
	    cout << ans.first << " " << ans.second << endl;
	    
	}	
}
