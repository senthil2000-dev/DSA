#include<bits/stdc++.h>
using namespace std;

bool search(string pat, string txt) {
    int n =txt.length();
    int m = pat.length();
    for(int i=0; i<=n-m; i++) {
        int j=0;
        for(j=0; j<m; j++) {
            if(txt[i+j] != pat[j]) 
                break;
        }
        if(j==m) return true;
    }
    return false;
}

int main() {
    cout<<search("a", "hqg")<<endl;
}
