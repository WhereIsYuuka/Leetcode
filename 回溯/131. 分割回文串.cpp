class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        int n = s.length();
        auto isHuiWen = [&](this auto&& isHuiWen, int l, int r) -> bool {
            while(l < r)
            {
                if(s[l++] != s[r--])
                {
                    return false;
                }
            }
            return true;
        };

        auto dfs = [&](this auto&& dfs, int start, int cur) -> void {
            if(cur == n)
            {
                res.emplace_back(path);
                return;
            }
            if(cur < n - 1)
                dfs(start, cur+1);
            if(isHuiWen(start, cur))
            {
                path.emplace_back(s.substr(start, cur - start + 1));
                dfs(cur+1, cur+1);
                path.pop_back();
            }
        };
        dfs(0, 0);
        return res;
    }
};class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        int n = s.length();
        auto isHuiWen = [&](this auto&& isHuiWen, int l, int r) -> bool {
            while(l < r)
            {
                if(s[l++] != s[r--])
                {
                    return false;
                }
            }
            return true;
        };

        auto dfs = [&](this auto&& dfs, int start, int cur) -> void {
            if(cur == n)
            {
                res.emplace_back(path);
                return;
            }
            if(cur < n - 1)
                dfs(start, cur+1);
            if(isHuiWen(start, cur))
            {
                path.emplace_back(s.substr(start, cur - start + 1));
                dfs(cur+1, cur+1);
                path.pop_back();
            }
        };
        dfs(0, 0);
        return res;
    }
};

// class Solution {
// public:
//     vector<vector<string>> partition(string s) {
//         vector<vector<string>> res;
//         vector<string> path;
//         int len = s.size();
        
//         auto dfs = [&](this auto&& dfs, int i) -> void
//         {
//             if(i == len)
//             {
//                 res.emplace_back(path);
//                 return;
//             }

//             for(int j = i; j < len; j++)
//             {
//                 if(isPalindrome(s, i, j))
//                 {
//                     path.emplace_back(s.substr(i, j - i + 1));
//                     dfs(j + 1);
//                     path.pop_back();
//                 }
//             }
//         };

//         dfs(0);
//         return res;
//     }

//     bool isPalindrome(const string& str, int l, int r)
//     {
//         while(l < r)
//         {
//             if(str[l++] != str[r--])
//                 return false;
//         }
//         return true;
//     }
// };