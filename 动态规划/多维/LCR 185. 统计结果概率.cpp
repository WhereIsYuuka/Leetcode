class Solution {
    public:
        vector<double> statisticsProbability(int num) {
            vector<double> res;
            vector<vector<int>> dp(num+1, vector<int>(num*6+1,0));
            for(int i = 1; i <= 6; i++)
                dp[1][i] = 1;
                
            for(int i = 2; i <= num; i++)
            {
                for(int j = i; j <= num*6; j++)
                {
                    for(int cur = 1; cur <= 6; cur++)
                    {
                        if(j - cur <= 0)
                            break;
                        dp[i][j] += dp[i-1][j-cur];
                    }
                }
            }
    
            int allSize = pow(6, num);
            for(int i = num; i <= num*6; i++)
            {
                res.emplace_back(dp[num][i] * 1.0 / allSize);
            }
            return res;
        }
    };