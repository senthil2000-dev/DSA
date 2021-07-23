#include<bits/stdc++.h> //leftmost nonrepeat
using namespace std;

int firstUniqChar(const string &s) {
    int f[26]; //firstIndex array
    memset(f, -1, sizeof(f));
    int n = s.length();
    for(int i=0; i<s.length(); i++) {
        if(f[s[i]-'a'] == -1) f[s[i]-'a'] = i;
        else f[s[i]-'a'] = -2;
    }
    int res = INT_MAX;
    for(int i=0; i<26; i++) {
        if(f[i]>=0) res = min(res, f[i]);
    }
    return res == INT_MAX? -1: res;
}

int main() {
    cout<<firstUniqChar("eetcode")<<endl;
}
