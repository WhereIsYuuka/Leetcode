class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> path;
        vector<int> visited(n, 0);
        dfs(nums, 0, path, visited, res);
        return res;
    }

    void dfs(vector<int>& nums, int num, vector<int>& path, vector<int>& visited, vector<vector<int>>& res)
    {
        if(num == nums.size())
        {
            res.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++)
        {
            if(visited[i] == 0)
            {
                visited[i] = 1;
                path.push_back(nums[i]);
                dfs(nums, num + 1, path, visited, res);
                path.pop_back();
                visited[i] = 0;
            }
        }
    }

};

// class Solution {
// public:
//     vector<int> val;
//     vector<int> v;
//     vector<vector<int>> ans;

//     void dfs(vector<int>& nums, int cur)
//     {
//         if(cur == nums.size())   //结束
//         {
//             ans.push_back(v);
//             return;
//         }
//         for(int i = 0; i < nums.size(); i++)
//         {
//             if(val[i] == 0)
//             {
//                 val[i] = 1;
//                 v.push_back(nums[i]);
//                 dfs(nums,cur+1);
//                 v.pop_back();
//                 val[i] = 0;
//             }
//         }
//         return;
//     }

//     vector<vector<int>> permute(vector<int>& nums) {
//         val = vector<int>(nums.size(), 0);
//         dfs(nums, 0);
//         return ans;
//     }
// };