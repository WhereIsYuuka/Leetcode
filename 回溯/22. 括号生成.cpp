class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path;
        dfs(res, path, n, n);
        return res;
    }

    void dfs(vector<string>& res, string& path, int left, int right) 
    {
        if(left == 0 && right == 0)
        {
            res.push_back(path);
            return;
        }
        if(left > 0)
        {
            path.push_back('(');
            dfs(res, path, left - 1, right);
            path.pop_back();
        }
        if(left < right)
        {
            path.push_back(')');
            dfs(res, path, left, right - 1);
            path.pop_back();
        }
    }
};

// class Solution {
// public:
//     vector<string> res;
//     vector<string> generateParenthesis(int n) {
//         if(n == 0)
//             return res = vector<string>();
//         string str;
//         create(res,str,n,n);
//         return res;
//     }
//     void create(vector<string>& res, string str, int l, int r)
//     {
//         if(l == 0 && r == 0)
//         {
//             res.push_back(str);
//             return;
//         }
//         if(l == 0)
//         {
//             create(res, str  + ')', l, r-1);
//         }
//         else if(l == r)
//         {
//             create(res, str  + '(', l-1, r);
//         }
//         else if(l < r)
//         {
//             create(res, str  + ')', l, r-1);
//             create(res, str  + '(', l-1, r);
//         }
//     }
// };