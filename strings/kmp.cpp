#include<bits/stdc++.h>
using namespace std;

void fillLPS(string pat, int m, int lps[]) {
    int len=lps[0]=0;
    int i=1;
    while(i<m) {
        if(pat[i] == pat[len]) {len++; lps[i]=len; i++;}
        else {
            if(len==0) {lps[i]=0; i++;}
            else {len=lps[len-1];}
        }
    }
}

vector<int> search(string pat, string txt) {
    vector<int> v;
    int n = txt.length();
    int m = pat.length();
    int lps[m];
    fillLPS(pat, m, lps);
    int i=0, j=0;
    while (i<n) {
        if(txt[i] == pat[j]) {i++; j++;}
        if(j==m) {v.push_back(i-j+1); j=lps[j-1];}
        if(i<n && txt[i] != pat[j]) {
            if(j==0) i++;
            else j=lps[j-1];
        }
    }
    if(v.size()==0) v.push_back(-1);
    return v;
}

int main() {
    vector<int> v = search("bat", "batmanandrobatarebat");
    for(int x: v) {
        cout<<x<<' ';
    }
}
