class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        int len = s.size();
        
        auto dfs = [&](this auto&& dfs, int i) -> void
        {
            if(i == len)
            {
                res.emplace_back(path);
                return;
            }

            for(int j = i; j < len; j++)
            {
                if(isPalindrome(s, i, j))
                {
                    path.emplace_back(s.substr(i, j - i + 1));
                    dfs(j + 1);
                    path.pop_back();
                }
            }
        };

        dfs(0);
        return res;
    }

    bool isPalindrome(const string& str, int l, int r)
    {
        while(l < r)
        {
            if(str[l++] != str[r--])
                return false;
        }
        return true;
    }
};