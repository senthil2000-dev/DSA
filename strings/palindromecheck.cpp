#include<bits/stdc++.h>
using namespace std;

int isPlaindrome(string S) {
    return equal(S.begin(), S.end(), S.rbegin());
}

int isPlaindrome2(const string &S) {
    int i=0;
    int j=S.length() - 1;
    while(i<j) {
        if(S[i]!=S[j]) return false;
        i++;j--;
    }
    return true;
}

int main() {
    cout<<isPlaindrome("acba")<<endl;
    cout<<isPlaindrome2("abba")<<endl;
    cout<<isPlaindrome2("")<<endl;
}
