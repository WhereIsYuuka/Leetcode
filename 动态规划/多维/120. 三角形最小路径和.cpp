class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> res(n, vector<int>(n));

        // 底层赋值
        for(int i = 0; i < n; i++)
        {
            res[n-1][i] = triangle[n-1][i];
        }

        for(int i = n-2; i >= 0; i--)
        {
            for(int j = 0; j <= i; j++)
            {
                res[i][j] = triangle[i][j] + min(res[i+1][j], res[i+1][j+1]);
            }
        }
        return res[0][0];
    }
};