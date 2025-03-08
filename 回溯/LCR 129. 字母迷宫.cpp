class Solution {
    public:
    int dirX[4] = {1,0,-1,0}, dirY[4] = {0,1,0,-1};
        bool wordPuzzle(vector<vector<char>>& grid, string target) {
            int m = grid.size(), n = grid[0].size();
            for(int i = 0; i < m; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(dfs(grid, target, i, j, 0))
                        return true;
                }
            }
            return false;
        }

        bool dfs(vector<vector<char>>& grid, string target, int x, int y, int idx)
        {
            if(grid[x][y] != target[idx])
                return false;
            if(idx == target.size() - 1)
                return true;
            char ch = grid[x][y];
            grid[x][y] = '.';
            for(int i = 0; i < 4; i++)
            {
                int nx = x + dirX[i], ny = y + dirY[i];
                if(nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size())
                    continue;
                if(dfs(grid, target, nx, ny, idx + 1))
                    return true;
            }
            grid[x][y] = ch;
            return false;
        }
    };