#include<bits/stdc++.h>
using namespace std;

int primeDigits(int n) {
    string s;
    while(n) {
        int rem = n%4;
        switch(rem) {
            case 1:
                s.push_back('2');
                break;
            case 2:
                s.push_back('3');
                break;
            case 3:
                s.push_back('5');
                break;
            case 0:
                s.push_back('7');
                n--;
                break;
        }
        n/=4;
    }
    reverse(s.begin(), s.end());
    return stoi(s);
}

int primeDigits2(int n) {
    string s;
    int len;
    long long prev = 0;
    //calculate len and number of nos of length 0 to len-1
    for(len=1; true; len++) {
        long long curr = prev + pow(4, len);
        if(n>prev && n<=curr) break;
        prev = curr;
    }
    
    for(int i=1; i<=len; i++) {
        for(int j=1; j<=4; j++) {
            if(pow(4, len-i) + prev < n) {
                prev += pow(4, len-i);
                continue;
            }
            switch(j) {
                case 1:
                    s.push_back('2');
                    break;
                case 2:
                    s.push_back('3');
                    break;
                case 3:
                    s.push_back('5');
                    break;
                case 4:
                    s.push_back('7');
                    break;
            }
            break;
        }
    }
    return stoi(s);
}

int main() {
    string s = "28";
    int n = stoi(s);
    cout<<primeDigits(28)<<endl;
    cout<<primeDigits2(28)<<endl;
}
