#include<bits/stdc++.h>
using namespace std;

//recursively add till one digit
// eg: ans(383) = ans(380+3) = ans(380) + ans(3) = ans(38) + ans(3) = and(38+3)
int addDigits(int num) {
    if(num<=9)
        return num;
    return addDigits(num/10 + num%10);
}

int main() {
    cout<<addDigits(383)<<endl;
}
