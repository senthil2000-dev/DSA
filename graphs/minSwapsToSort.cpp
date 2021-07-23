#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    int n = nums.size(), ans =0;
	    pair<int, int> rsortInd[n];
	    for(int i=0; i<n; i++) {
	        rsortInd[i].first = nums[i];
	        rsortInd[i].second = i;
	    }
	    
	    sort(rsortInd, rsortInd + n);
	    
	    vector<bool> visited(n, false);
	    for(int i=0; i<n; i++) {
	        //optional to check to optimise
	        if(visited[i] || rsortInd[i].second == i) continue;
	        int j = i;
	        int cSize =0;
	        while(!visited[j]) {
	            visited[j] = true;
	            j = rsortInd[j].second;
	            cSize++;
	        }
	        if(cSize!=0) ans+=(cSize-1);
	    }
	    
	    return ans;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
