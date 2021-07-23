#include<bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;

int power(int x, int y) {
    long long res = 1;
    while(y) {
        if(y&1)
            (res*=x)%=mod;
        x = (x*1ll*x)%mod;
        y = y>>1;
    }
    return res;
}

int main() {
    int n;
    cin>>n;
    cout<<power(2, n);
}
