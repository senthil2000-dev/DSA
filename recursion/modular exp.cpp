#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

//iterative
long long power(int N,int R) {
    long long res = 1;
    N = N%mod;
    while(R>0) {
        if(R & 1)
            res = (res*N)%mod;
        N = (N*1ll*N) % mod;
        R = R>>1;
    }
    return res;
}

//recursive
long long power2(int N,int R) {
    if(R==0) return 1;
    long long temp = power2(N, R/2) % mod;
    temp = (temp*temp)%mod;
    return R%2 ? (temp*N)%mod: temp;
}

int main() {
    cout<<power(12, 21)<<endl;
    cout<<power2(12, 21)<<endl;
}
