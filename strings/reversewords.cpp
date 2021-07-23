#include<bits/stdc++.h>
using namespace std;

string reverseWords(string &s) { 
    int start = 0;
    int n = s.length();
    for(int end=0; end<n; end++) {
        if(s[end] == '.') {//here . as space
            reverse(s.begin()+start, s.begin()+end);
            start = end+1;
        }
    }
    reverse(s.begin()+start, s.begin()+n);
    reverse(s.begin(), s.end());
    return s;
}

string rev(string &s, int l, int h) {
    string res = "";
    for(int i=h; i>=l; i--) {
        res.push_back(s[i]);
    }
    return res;
}

string reverseWords2(string &s) {
    string ans = "";
    int n = s.length();
    int start = 0, trail=n-1;
    while(s[start] == ' ') start++;
    while(s[trail] == ' ') trail--;
    for(int end=start; end<=trail; end++) {
        if(s[end] == ' ') {
            ans += rev(s, start, end-1) + ' ';
            while(s[end] == ' ') end++;
            start = end;
        }
    }
    ans += rev(s, start, trail);
    reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    string s = "Welcome.to.nitt";
    string s1 = "   Welcome to  nitt  ";
    cout<<reverseWords(s)<<endl;
    cout<<reverseWords2(s1)<<endl;
}

