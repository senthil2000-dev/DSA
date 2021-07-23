#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
#define N 2
#define f(i, n) for(int i=0; i<n; i++)

void multiply(ll A[N][N], ll B[N][N]) {
    ll res[N][N];
    f(i, N) f(j,N) {
        res[i][j] = 0;
        f(k, N)
            (res[i][j]+=A[i][k]*B[k][j]) %= M;
    }
    f(i, N) f(j, N) A[i][j] = res[i][j]; 
}

void power(ll mat[N][N], ll pow) {
    ll id[N][N];
    f(i, N) f(j, N) {
      if(i == j) id[i][j] = 1;
      else id[i][j] = 0; 
    } 
    while(pow>0) {
       if(pow & 1)
        multiply(id, mat);
      multiply(mat, mat);
      pow = pow>>1; 
    }
		f(i, N) f(j, N) mat[i][j]=id[i][j]; 
}

ll fib(ll n) {
    if(n<=2) return n;
    ll mat[N][N] = {
        {0, 1},
        {1, 1}
    };
    power(mat, n-1);
    ll ans = (mat[0][0] + 2*mat[1][0]) % M;
		return ans;
}

int main() {
    ll t;
    cin>>t;
    while(t--) {
        ll n;
        cin>>n;
        cout<<fib(n)<<endl;
    }
}
