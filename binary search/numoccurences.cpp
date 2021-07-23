#include<bits/stdc++.h>
using namespace std;

class Solution{
public:	
	int count(int arr[], int n, int x) {
	    int lo = lower_bound(arr, arr+n, x) - arr;
        int up = upper_bound(arr, arr+n, x) - arr;
        return up-lo;
	}
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}
