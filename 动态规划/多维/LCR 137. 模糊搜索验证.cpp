class Solution {
    public:
        bool articleMatch(string s, string p) {
            int n = s.size() + 1, m = p.size() + 1;
            vector<vector<bool>> dp(n, vector<bool>(m, false));
            dp[0][0] = true;
            for(int i = 2; i < m; i += 2)
                if(p[i-1] == '*')
                    dp[0][i] = dp[0][i-2];
            
            for(int i = 1; i < n; i++)
            {
                for(int j = 1; j < m; j++)
                {
                    if(p[j-1] == '*')
                    {
                        if(dp[i][j-2])  //*与前面的次数为0
                            dp[i][j] = true;
                        else if(dp[i-1][j] && s[i-1] == p[j-2])
                            dp[i][j] = true;
                        else if(dp[i-1][j] && p[j-2] == '.')
                            dp[i][j] = true;
                    }
                    else    //p[j-1] != '*'
                    {
                        if(dp[i-1][j-1] && s[i-1] == p[j-1])
                            dp[i][j] = true;
                        else if(dp[i-1][j-1] && p[j-1] == '.')
                            dp[i][j] = true;
                    }
                }
            }
            return dp[n-1][m-1];
        }
    };