#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.length();
    if(!n) return n;
    int prev[256];
    memset(prev, -1, sizeof(prev));
    int maxEnd[n];
    for(int i=0; i<n; i++) {
        if(i==0) maxEnd[i] = 1;
        else if(prev[s[i]]<i-maxEnd[i-1]) { //includes prev[s[i]]=-1 case also
            maxEnd[i] = maxEnd[i-1] + 1;
        }
        else {
            maxEnd[i] = i-prev[s[i]];
        }
        prev[s[i]]=i;
    }
    return *max_element(maxEnd, maxEnd + n);
}

int lengthOfLongestSubstring2(string s) { //less space just maintain prev start index
    int n = s.length();
    vector<int> prev(256, -1);
    int i=0, res=0;
    for(int j=0; j<n; j++) {
        i=max(i, prev[s[j]]+1);
        res = max(res, j-i+1);
        prev[s[j]] = j;
    }
    return res;
}

int main() {
    cout<<lengthOfLongestSubstring("")<<endl;
    cout<<lengthOfLongestSubstring("abcabcdbb")<<endl;
    cout<<lengthOfLongestSubstring2("abcabcdbb")<<endl;
}
