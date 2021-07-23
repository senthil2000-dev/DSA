#include<bits/stdc++.h>
using namespace std; 
const long long mod=1000000007; 
// alway better to use const long long mod to type cast rest stuff that is operated with this and equated

unsigned long long binomial_coeff(int k, int n) {
    // this is okay for small n like 20..
    if(k>n) return 0;
    if(k>n-k)   k=n-k;
    unsigned long long res = 1;
    for(int i=0; i<k; i++) {
        res*=(n-i);
        res/=(i+1);
    }
    return res;
}

int binomial_coeff_under_modulo(int k, int n) {
    //can go upto n 2000 and above
    if(k>n)     return 0;
    if(k>n-k)   k=n-k;
    int res = 1;
    int inv[k+1];
    inv[1] = 1;
    for(int i=2; i<=k; i++) {
        inv[i] = mod-((mod/i)*(inv[mod%i]))%mod; //important eqn
    }
    for(int i=2; i<=k; i++) {
        res = ((res%mod)*(inv[i]%mod))%mod;
    }
    for(int i=n; i>=(n-k+1); i--) {
        res = ((res%mod)*(i%mod))%mod;
    }
    return res;
}

int gcdExtended(int a, long long b, int &x, int &y) {
    if(a == 0) {
        x = 0;
        y = 1;
        return b;
    }

    int xprev, yprev;
    int gcd = gcdExtended(b%a, a, xprev, yprev);
    x = yprev - (b/a)*xprev;
    y = xprev;
    return gcd;
}

int modInv(int a) {
    int x, y;
    int g = gcdExtended(a, mod, x, y);
    if(g!=1)    return -1;
    else {
        return (x%mod + mod)%mod;
    }
}

unsigned long long numTrees(int n) {
    // unsigned long long bc = binomial_coeff(n, 2*n);
    // return bc/(n+1);
    unsigned long long bc = binomial_coeff_under_modulo(n, 2*n);
    int mi = modInv(n+1);
    return (bc*mi)%mod;
}

int main() {
    int n;
    cin>>n;
    cout<<numTrees(n)<<endl;
    cout<<binomial_coeff(3, 5)<<endl;
    cout<<binomial_coeff_under_modulo(3, 5)<<endl;
}
