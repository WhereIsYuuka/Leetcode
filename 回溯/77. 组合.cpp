class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(n, k, 1, path, res);
        return res;
    }

    void dfs(int n, int k, int num, vector<int>& path, vector<vector<int>>& res)
    {
        if(path.size() == k)
        {
            res.push_back(path);
            return;
        }
        for(int i = num; i <= n; i++)
        {
            path.push_back(i);
            dfs(n, k, i+1, path, res);
            path.pop_back();
        }
    }
};