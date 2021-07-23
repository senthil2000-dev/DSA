#include<bits/stdc++.h>
using namespace std;

//easy alternative to cycleleader version
void evenAtEnd(string s){
    int i,n;
    n=s.size();
    for(i=0;i<n;i++){
        if(i%2!=0){
            // s.insert(s.begin()+s.size(),s[i]);
            s.push_back(s[i]);
        }
    }
    for(i=1;i<=n/2;i++){
        //when we erase index 1, index 3 comes to 2 and so...
        s.erase(i,1);
    }
    cout << s << endl;
}

int main(){
    string s = "a1b2c3d4";
    evenAtEnd(s);
    return 0;
}
