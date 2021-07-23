#include<bits/stdc++.h>
using namespace std;

//zero based indexing in jos function
int jos(int n, int k) {
    if(n==1)
        return 0;
    else
        return (jos(n-1, k) + k)%n;
}

int findTheWinner(int n, int k) {
    return jos(n, k) + 1;
}

int main() {
    int n, k;
    cin>>n>>k;
    cout<<findTheWinner(n, k)<<endl;   
}

//recurrene relation findTheWinner(n-1, k) + k-1)%n + 1
// k+1 th person shoots a person who is joshepus(n-1, k)-1 ahead of him
//we use a trick like to subtract one inside mod and add one outside so that if survivor is n it doesnt give result 0 and gives 1
