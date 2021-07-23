#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long fact(int n) { //works for n<=15
    long long fact = 1;
    for(int i=2; i<=n; i++) {
        fact*=i;
    }
    return fact;
}

int findRank(string s) {
    int n = s.length();
    // long long fa = fact(n);
    long long factdp[n];
    factdp[0]=1;
    for(int i=1; i<n; i++) {
        factdp[i] = (i*factdp[i-1])%mod; //i between 1 to 26 so i%mod = i 
    }
    int h[26]={0};
    int res =1;
    for(int i=0; i<n; i++) {
        if(h[s[i]-'a']>0) return 0;
        h[s[i]-'a']++;
    }
    for(int i=1; i<26; i++) {
        h[i]+=h[i-1];
    }
    for(int i=0; i<n-1; i++) {
        long long fa = factdp[n-1-i];
        (res += s[i]!='a'? (fa*h[s[i]-'a'-1])%mod: 0)%=mod; //h array has values between 0 to 26(so no mod)
        for(int j=s[i]-'a'; j<26; j++) h[j]--;
    }
    return res;
}

int main() {
    cout<<findRank("acbd")<<endl;
}
