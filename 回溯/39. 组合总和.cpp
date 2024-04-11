class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        int val = 0;
        if(candidates.empty())
            return res;
        dfs(candidates, 0, path, res, val, target);
        return res;
    }

    void dfs(vector<int>& candidates, int num, vector<int>& path, vector<vector<int>>& res, int& val, int target)
    {
        if(val == target)
        {
            res.push_back(path);
            return;
        }
        if(val > target)
            return;
        for(int i = num; i < candidates.size(); i++)
        {
            path.push_back(candidates[i]);
            val += candidates[i];
            dfs(candidates, i, path, res, val, target);
            val -= candidates[i];
            path.pop_back();
        }
    }
};

// class Solution {
// public:
//     vector<int> val;
//     vector<vector<int>> res;
//     int sum = 0;
//     void dfs(vector<int>& candidates, int target, int cur)
//     {
//         if(sum == target)   //成功结束
//         {
//             res.push_back(val);
//             return;
//         }
//         if(sum > target)    //失败
//             return;
//         for(int i = cur; i < candidates.size(); i++)
//         {
//             sum += candidates[i];
//             val.push_back(candidates[i]);
//             dfs(candidates, target, i);
//             sum -= candidates[i]; 
//             val.pop_back();
//         }
//         return;
//     }

//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         dfs(candidates, target, 0);
//         return res;
//     }
// };