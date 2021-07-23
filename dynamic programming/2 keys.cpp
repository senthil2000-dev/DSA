class Solution {
public:
    int minSteps(int n) {
        int dp[n+1]; //dp[j] represents minimum no of keypresses for length j
        dp[1] = 0;
        for(int i=2; i<=n; i++) {
            //j refers to no of letters in clipboard (copy and paste i/j-1 times, just page is included here as copy and paste n times = copy+paste 1 time and paste n-1 times)
            for(int j=i/2; j>=1; j--) { //the larger j for i%j=0 will be the crct breakpoint because copy paste just 2 times is better than 3 times and so on...
                if(i%j == 0) {
                    dp[i] = dp[j] + i/j;
                    break;
                }
            }
        }        
        return dp[n];
    }
};
