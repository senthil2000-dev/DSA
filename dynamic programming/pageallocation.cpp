#include<bits/stdc++.h>
using namespace std;
#define f(i, s, n) for(int i=s; i<n; i++)
#define fe(i, s, n) for(int i=s; i<=n; i++)

int books(int* A, int n1, int B) {
    if(n1<B) return -1;
    int dp[B+1][n1+1];
    int sum;
    fe(i, 1, n1) {sum = 0; dp[1][i] = accumulate(A, A+i, sum);}
    fe(i, 1, B) dp[i][1] = A[0];
    fe(i, 2, B) {
        fe(j, 2, n1) {
            dp[i][j] = INT_MAX;
            for(int k=1; k<j; k++) {
                sum=0;
                dp[i][j] = min(dp[i][j], max(dp[i-1][k], accumulate(A+k, A+j, sum)));
            }
        }
    }
    return dp[B][n1];
}

//interview bitz soln
int books(vector<int> &A, int B) {
    int n1 = A.size();
    if(n1<B) return -1;
    int dp[B+1][n1+1];
    int sum;
    fe(i, 1, n1) {sum = 0; dp[1][i] = accumulate(A.begin(), A.begin()+i, sum);}
    fe(i, 1, B) dp[i][1] = A[0];
    fe(i, 2, B) {
        fe(j, 2, n1) {
            dp[i][j] = INT_MAX;
            for(int k=1; k<j; k++) {
                sum=0;
                dp[i][j] = min(dp[i][j], max(dp[i-1][k], accumulate(A.begin()+k, A.begin()+j, sum)));
            }
        }
    }
    return dp[B][n1];
}

int main() {
    int A[] = {73, 58, 30, 72, 44, 78, 23, 9};
    int B = 5;
    cout<<books(A, 8, B)<<endl;
}
