#include<bits/stdc++.h>
using namespace std;

int modified(string str){
    int i=0;
    int n = str.length();
    int count = 0;
    while(i<=n-3) {
        if(str[i] == str[i+1] && str[i+1] == str[i+2]) count++, i+=2;
        else i++;
    }
    return count;
}

int main() {
    cout<<modified("aaaaa");
}
