class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        int len = digits.length();
        if(len <= 0)
            return res;
        unordered_map<int, string> ump = {
            {2, "abc"},{3, "def"},{4, "ghi"},{5, "jkl"},
            {6, "mno"},{7, "pqrs"},{8, "tuv"},{9,"wxyz"}
        };
        string str = "";
        auto dfs = [&](this auto&& dfs, int idx) -> void {
            if(idx == len)
            {
                res.emplace_back(str);
                return;
            }
            string curNumStr = ump[digits[idx] - '0'];
            for(int i = 0; i < curNumStr.length(); i++)
            {
                str += curNumStr[i];
                dfs(idx+1);
                str.pop_back();
            }
        };
        dfs(0);
        return res;
    }
};

// class Solution {
// public:
//     vector<string> letterCombinations(string digits) {
//         vector<string> res;
//         if(digits.empty())
//             return res;
//         vector<string> dir = {"abc","def","ghi","jkl","mno",
//         "pqrs","tuv","wxyz"};
//         string path;
//         dfs(digits, 0, path, res, dir);
//         return res;
//     }

//     void dfs(string& digits, int num, string& path, vector<string>& res, vector<string>& dir)
//     {
//         if(num == digits.size())
//         {
//             res.push_back(path);
//             return;
//         }
//         for(auto ch : dir[digits[num] - '2'])
//         {
//             path.push_back(ch);
//             dfs(digits, num + 1, path, res, dir);
//             path.pop_back();
//         }
//     }
// };

// class Solution {
// public:
//     vector<string> letterCombinations(string digits) {
//         vector<string> res;
//         int n = digits.length();
//         if(n < 1)
//             return {};
//         vector<string> strs = {"abc", "def","ghi","jkl", "mno", "pqrs", "tuv", "wxyz"};
//         string path = "";

//         auto dfs = [&](this auto&& dfs, int i) -> void
//         {
//             if(i == n)
//             {
//                 res.emplace_back(path);
//                 return;
//             }
//             for(auto ch : strs[digits[i] - '2'])
//             {
//                 path.push_back(ch);
//                 dfs(i+1);
//                 path.pop_back();
//             }
//         };
//         dfs(0);
//         return res;
//     }
// };