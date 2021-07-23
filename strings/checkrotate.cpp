#include<bits/stdc++.h>
using namespace std;

bool rotateString(string s, string goal) {
    return (s.length() == goal.length() && ((s+s).find(goal) != string::npos));
}

int main() {
    cout<<rotateString("aacde", "cdeaa")<<endl;
    cout<<rotateString("abcde", "abced")<<endl;
}
