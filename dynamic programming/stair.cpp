#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
void staircase(int n) {
	int steps[n+1];
	steps[1] = 1;
	steps[2] = 2;
	steps[3] = 4;
	for(int i=4; i<=n; i++) {
		steps[i] = (steps[i-3]+steps[i-1]+steps[i-2]) % M;
	}
	cout<<steps[n]<<endl;
}

int main() {
  int t;
	cin>>t;
  while(t--) {
		int n;
		cin>>n;
		staircase(n);
	}  
}
