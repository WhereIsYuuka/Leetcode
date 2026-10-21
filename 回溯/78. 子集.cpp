#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        int n = nums.size();
        auto dfs = [&](this auto&& dfs, int idx) -> void{
            if(idx == n)
            {
                res.push_back(path);
                return;
            }
            path.emplace_back(nums[idx]);
            dfs(idx+1);
            path.pop_back();
            dfs(idx+1);
        };
        dfs(0);
        return res;
    }
};