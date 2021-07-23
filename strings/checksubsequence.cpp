#include<bits/stdc++.h>
using namespace std;

bool isSubsequence(const string &s, const string &t) {
    int j=0;
    for(int i=0; j<s.length() && i<t.length(); i++) {
        if(s[j]==t[i]) j++;
    }
    return (j==s.length());
}

bool recur(const string &s, const string &t, int m, int n) {
    if(m==0) return true;
    if(n==0) return false;
    if(s[m-1]==t[n-1]) return recur(s, t, m-1, n-1);
    else return recur(s, t, m, n-1);
}

bool isSubsequence2(const string &s, const string &t) {
    int m = s.length();
    int n= t.length();
    return recur(s, t, m, n);
}

int main() {
    cout<<isSubsequence("abc", "ahbgdc")<<endl;
    cout<<isSubsequence("axc", "ahbgdc")<<endl;
    cout<<isSubsequence2("abc", "ahbgdc")<<endl;
    cout<<isSubsequence2("axc", "ahbgdc")<<endl;
}
