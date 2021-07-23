#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define f(i, n) for(int i=0; i<n; i++)

signed main() {
    int t;
    cin>>t;
    while(t--) {
        int n, res = 0;
        int freq[32];
        memset(freq, 0, sizeof(freq));
        cin>>n;
        f(i, n) {
            int mask = 0;
            string s;
            cin>>s;
            for(char ch: s) {
                if (ch == 'a') mask |= 1<<0; 
                if (ch == 'e') mask |= 1<<1; 
                if (ch == 'i') mask |= 1<<2; 
                if (ch == 'o') mask |= 1<<3; 
                if (ch == 'u') mask |= 1<<4; 
            }
            freq[mask]++;
        }
        for(int i=1; i<32; i++) {
            for(int j=i+1; j<32; j++) {
                if((i|j) == 31)
                    res += (freq[i]*freq[j]);
            }
        }
        res += (freq[31]*(freq[31]-1))/2;
        cout<<res<<endl;
    }
}
