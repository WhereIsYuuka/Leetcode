class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int len = s.size();
        vector<short> dp(len + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= len; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(dp[j] && dict.find(s.substr(j, i-j)) != dict.end())   //dp[j]表示前j个字符是否可以拆分
                {
                    dp[i] = 1;
                    break;
                }
            }
        }
        return dp[len] ? true : false;
    }
};