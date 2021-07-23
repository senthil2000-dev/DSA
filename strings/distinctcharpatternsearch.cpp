#include<bits/stdc++.h>
using namespace std;

void search(string pat, string txt) {
    // O(n)
    int n =txt.length();
    int m = pat.length();
    for(int i=0; i<=n-m;) {
        int j=0;
        for(j=0; j<m; j++) {
            if(txt[i+j] != pat[j]) 
                break;
        }
        if(j==m) cout<<i<<' ';
        if(j==0) i++;
        else i+=j;
    }
}

int main() {
    search("ABCD", "ABCDBABCDAAABC");
}
