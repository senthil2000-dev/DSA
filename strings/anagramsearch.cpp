#include<bits/stdc++.h>
using namespace std;

bool areSame(char arr1[], char arr2[]) {
    for(int i=0; i<26; i++) {
        if(arr1[i]!=arr2[i]) return false; 
    }
    return true;
}

vector<int> findAnagrams(string s, string p) {
    vector<int> v;
    if(p.length()>s.length()) return v;
    char CT[26] = {0}, CP[26] = {0};
    for(int i=0; i<p.length(); i++) {
        CT[s[i]-'a']++;
        CP[p[i]-'a']++;
    }
    int i;
    for(i=p.length(); i<s.length(); i++) {
        if(areSame(CT, CP)) v.push_back(i-p.length());
        CT[s[i]-'a']++;
        CT[s[i-p.length()]-'a']--;
    }
    if(areSame(CT, CP)) v.push_back(i-p.length());
    return v;
}

int main() {
    vector<int> v = findAnagrams("cbadbcsabc", "abc");
    for(int x: v) cout<<x<<" ";
}
