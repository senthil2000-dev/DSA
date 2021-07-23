#include<bits/stdc++.h>
using namespace std;
#define pr 257 //prime
#define d 256

vector<int> search(string pat, string txt) {
    int n =txt.length();
    int m = pat.length();
    vector<int> v;
    // precompute h as d^m-1
    int h=1;
    for(int i=1; i<m; i++) {
        h = (h*d)%pr;
    }
    int p = 0, q =0;
    // first hash for pattern and text 
    for(int i=0; i<m; i++) {
        p = (p*d + txt[i])%pr;
        q = (q*d + pat[i])%pr;
    }
    for(int i=0; i<=n-m; i++) {
         if(p==q) {
            int j=0;
            for(j=0; j<m; j++) {
                if(txt[i+j] != pat[j]) 
                    break;
            }
            if(j==m) v.push_back(i+1);
        }
        if(i!=n-m) {
            p = (d*(p-txt[i]*h) + txt[i+m])%pr;
            if(p<0) p+=pr;
        }
    }
    if(v.size() == 0) v.push_back(-1);
    return v;
}

int main() {
    vector<int> v = search("q", "hqg");
    for(int x: v) {
        cout<<x<<' ';
    }
}
