#include<bits/stdc++.h>
using namespace std;

bool areIsomorphic(const string &str1, const string &str2)
{   if(str1.length() != str2.length()) return false;
    unordered_map<char, char> mp;
    bool visited[256] = {false};
    for(int i=0; i<str1.length(); i++) {
        if(mp.find(str1[i]) != mp.end()) {
            if(mp[str1[i]]!=str2[i]) return false;
            else continue;
        }
        else {
            if(visited[str2[i]]) return false;
            mp[str1[i]] = str2[i];
            visited[str2[i]] = true;
        }
    }
    return true;
}

int main() {
    cout<<areIsomorphic("rfkqyuqf", "jkxyqvnr")<<endl;
    cout<<areIsomorphic("pijthbsfy", "fvladzpbf")<<endl;
}
