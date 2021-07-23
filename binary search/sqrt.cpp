#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    long long int floorSqrt(long long int x) 
    {
        long long l=1, h=x, mid, ans=-1;
        while(l<=h) {
            mid = l+(h-l)/2;
            long long sq = mid*mid;
            if(sq == x) return mid;
            else if(sq<x) {
                ans = mid;
                l = mid+1;
            }
            else 
                h = mid-1;
        }
        return ans; 
    }
};

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		Solution obj;
		cout << obj.floorSqrt(n) << endl;
	}
    return 0;   
}
