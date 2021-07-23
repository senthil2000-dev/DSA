#include<bits/stdc++.h>
using namespace std;
#define f(i, n) for(int i=0; i<n; i++)

int lengthOfLIS2(int nums[], int n) {
	//non decreasing
    // binary search O(nlogn)
    int tail[n];
    int length = 1;
    tail[0] = nums[0];
    for(int i=1; i<n; i++) {
        if(nums[i] >= tail[length-1]) {
            tail[length++] = nums[i];
        }
        else {
            int ceilInd = upper_bound(tail, tail+length, nums[i]) - tail;
            tail[ceilInd] = nums[i];
        }
    }
    return length;
}

int lengthOfLIS(int nums[], int n) {
	//non decreasing
	if(!n) return n;
	int dp[n];
	dp[0] = 1;
	for(int i=1; i<n; i++) {
			dp[i] = 1;
			for(int j=0; j<i; j++) {
				if(nums[j]<=nums[i]) {
					dp[i] = max(dp[i], dp[j]+1);
				}
			}
	}
	return *max_element(dp, dp+n);
}

int buildbridges(vector<pair<int, int>> &v, int n) {
	sort(v.begin(), v.end());
	int second[n];
	f(i, n)	second[i] = v[i].second;
	return lengthOfLIS2(second, n);
}

int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		cin>>n;
		vector<pair<int, int>> pairs;
		int temp;
		f(i, n) {
			cin>>temp;
			pairs.push_back({temp, 0});
		}
		f(i, n) {
			cin>>temp;
			pairs[i].second = temp;
		}
		cout<<buildbridges(pairs, n)<<endl;
	}
}
