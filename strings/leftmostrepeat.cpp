// first occurence
#include<bits/stdc++.h>
using namespace std;

int repeatedCharacter (string s) { 
    int f[256]; //first occurence array
    fill(f, f+256, -1);
    int res=INT_MAX;
    for(int i=0; i<s.length(); i++) {
        if(f[s[i]]==-1) f[s[i]] = i;
        else {
            res = min(res, f[s[i]]);
        }
    }
    return res==INT_MAX ? -1: res;
}

int repeatedCharacter2 (string s) { 
    bool visited[256]; //traverse from right and just see if already seen the char and update(less comparisons)
    fill(visited, visited+256, false);
    int res=-1;
    for(int i=s.length()-1; i>=0; i--) {
        if(visited[s[i]]) res=i;
        else visited[s[i]] = true;
    }
    return res;
}

int main() {
    cout<<repeatedCharacter("hgeeksforgeeksg")<<endl;;
}
