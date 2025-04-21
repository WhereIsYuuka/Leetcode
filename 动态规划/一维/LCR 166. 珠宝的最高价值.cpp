class Solution {
    public:
        int jewelleryValue(vector<vector<int>>& frame) {
            int n = frame.size(), m = frame[0].size();
            vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
            for(int i = 1; i <= n; i++)
                dp[i][1] = frame[i-1][0];
            for(int j = 1; j <= m; j++)
                dp[1][j] = frame[0][j-1];
    
            for(int i = 1; i <= n; i++)
            {
                for(int j = 1; j <= m; j++)
                {
                    dp[i][j] = max(dp[i-1][j] + frame[i-1][j-1], dp[i][j-1] + frame[i-1][j-1]);
                }
            }
            return dp[n][m];
        }
    };