class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
            return 0;
        vector<vector<int>> res(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++)
            if(obstacleGrid[i][0] == 1)
                break;
            else
                res[i][0] = 1;
        for(int i = 0; i < n; i++)
            if(obstacleGrid[0][i] == 1) 
                break;
            else
                res[0][i] = 1;

        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
            {
                if(obstacleGrid[i][j] == 1)
                    continue;
                res[i][j] = res[i-1][j] + res[i][j-1];
            }
        }
        return res[m-1][n-1];
    }
};