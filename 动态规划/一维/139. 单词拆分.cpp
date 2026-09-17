class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i = 0; i < n; i++)
        {
            if(!dp[i])
                continue;
            for(auto& it : wordDict)
            {
                if(it.length() + i <= n && s.substr(i, it.length()) == it)
                    dp[i + it.length()] = true;
            }
        }
        return dp[n];
    }
};

// class Solution {
// public:
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> dict(wordDict.begin(), wordDict.end());
//         int len = s.size();
//         vector<short> dp(len + 1, 0);
//         dp[0] = 1;
//         for(int i = 1; i <= len; i++)
//         {
//             for(int j = 0; j < i; j++)
//             {
//                 if(dp[j] && dict.find(s.substr(j, i-j)) != dict.end())   //dp[j]表示前j个字符是否可以拆分
//                 {
//                     dp[i] = 1;
//                     break;
//                 }
//             }
//         }
//         return dp[len] ? true : false;
//     }
// };