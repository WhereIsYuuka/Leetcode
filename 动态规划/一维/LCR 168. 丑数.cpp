class Solution {
    public:
        int nthUglyNumber(int n) {
            vector<int> dp(n, 0);
            dp[0] = 1;
            int n2 = 0, n3 = 0, n5 = 0;
            for(int i = 1; i < n; i++)
            {
                int num2 = 2*dp[n2], num3 = 3*dp[n3], num5 = 5*dp[n5];
                dp[i] = min(min(num2, num3), num5);
                if(dp[i] == num2)
                    n2++;
                if(dp[i] == num3)
                    n3++;
                if(dp[i] == num5)
                    n5++;
            }
            return dp[n-1];
        }
    };