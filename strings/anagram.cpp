#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    if(s.length() != t.length()) return false;
    int C[26] = {0};
    for(int i=0; i<s.length(); i++) {
        C[s[i]-'a']++;
        C[t[i]-'a']--;
    }
    for(int i=0; i<26; i++) {
        if(C[i]!=0) {cout<<C[i]; return false;}
    }
    return true;
}

int main() {
    cout<<isAnagram("pathogen", "genopath")<<endl;
}
