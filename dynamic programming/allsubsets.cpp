#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f(i, n) for(int i=0; i<n; i++)

int main() {
    ll t;
    cin>>t;
    int tot = 1<<4;
    while(t--) {
        int arr[4];
        bool flag = false;
        f(i, 4) cin>>arr[i];
        f(mask, tot) {
            int sum = 0;
            f(i, 4) {
                int temp = 1<<i;
                if(temp & mask) {
                    sum+=arr[i];
                }
            }
            if(sum == 0 && mask!=0) {
                flag=true;
                break;
            } 
        }
        if(flag) cout<<"YES"<<endl;
        else cout<<"NO"<<endl; 
    }
}
