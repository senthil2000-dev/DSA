#include<bits/stdc++.h>
using namespace std;

string caseSort(string &str, int n) {
    string lower;
    string upper;
    for(char c: str) {
        if(islower(c)) {
            lower.push_back(c);
        }
        else if(isupper(c)) {
            upper.push_back(c);
        }
    }
    sort(lower.begin(), lower.end());
    sort(upper.begin(), upper.end());
    int i=0, j=0;
    for(int k=0; k<str.length(); k++) {
        char c = str[k];
        if(islower(c)) {
            str[k] = lower[i++];
        }
        else if(isupper(c)) {
            str[k] = upper[j++];
        }
    }
    return str;
}

int main() {
    string s = "defRTSersUXI";
     cout<<caseSort(s, 12)<<endl;
}
