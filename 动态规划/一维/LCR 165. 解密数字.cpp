class Solution {
    public:
        int crackNumber(int ciphertext) {
            string str = to_string(ciphertext), tmp;
            int len = str.length();
            vector<int> dp(len+1, 1);
            for(int i = 2; i <= len; i++)
            {
                tmp = str.substr(i-2, 2);
                if(tmp >= "10" && tmp <= "25")
                {
                    dp[i] = dp[i-1] + dp[i-2];
                }
                else
                {
                    dp[i] = dp[i-1];
                }
            }
            return dp[len];
        }
    };