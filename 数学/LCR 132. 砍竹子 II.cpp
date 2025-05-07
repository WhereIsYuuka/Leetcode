class Solution {
    public:
        // int cuttingBamboo(int bamboo_len) {
        //     if(bamboo_len < 4)
        //         return bamboo_len - 1;
        //     vector<int> dp(bamboo_len + 1, 0);
        //     for(int i = 1; i < 4; i++)
        //         dp[i] = i;
        //     int tmpMax = 0;
        //     for(int i = 4; i <= bamboo_len; i++)
        //     {
        //         tmpMax = 0;
        //         for(int j = 1; j <= i / 2; j++)
        //         {
        //             tmpMax = max(tmpMax, dp[j] * dp[i-j] % 1000000007);
        //         }
        //         dp[i] = tmpMax;
        //     }
        //     return dp[bamboo_len];
        // }
        int cuttingBamboo(int bamboo_len) {
            if(bamboo_len < 4)
                return bamboo_len-1;
            long res = 1;
            int mod = 1e9+7;
            if(bamboo_len % 3 == 1)
            {
                res = 4;
                bamboo_len -= 4;
            }
            else if(bamboo_len % 3 == 2)
            {
                res = 2;
                bamboo_len -= 2;
            }
            while(bamboo_len)
            {
                res = res * 3 % mod;
                bamboo_len -= 3;
            }
            return res;
        }
    };