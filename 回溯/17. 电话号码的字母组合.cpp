class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty())
            return res;
        vector<string> dir = {"abc","def","ghi","jkl","mno",
        "pqrs","tuv","wxyz"};
        string path;
        dfs(digits, 0, path, res, dir);
        return res;
    }

    void dfs(string& digits, int num, string& path, vector<string>& res, vector<string>& dir)
    {
        if(num == digits.size())
        {
            res.push_back(path);
            return;
        }
        for(auto ch : dir[digits[num] - '2'])
        {
            path.push_back(ch);
            dfs(digits, num + 1, path, res, dir);
            path.pop_back();
        }
    }
};

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