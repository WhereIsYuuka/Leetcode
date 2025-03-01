class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    res++;
                    dfs(grid, i, j);
                }
            }
        }
        return res;
    }

    int dfs(vector<vector<char>>& grid, int i, int j)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == '0')
            return 0;
        grid[i][j] = '0';
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j+1);
        dfs(grid, i, j-1);
        return 1;
    }
};

// class Solution {
// public:
//     int m,n;
//     int cx[4] = {-1,0,1,0}, cy[4] = {0,-1,0,1};   //方向

//     int numIslands(vector<vector<char>>& grid) { 
//         int cnt = 0;
//         m = grid.size(); 
//         n = grid[0].size();
//         for(int i = 0; i < m; i++)
//         {
//             for(int j = 0; j < n; j++)
//             {
//                 if(grid[i][j] == '1')
//                 {
//                     dfs(grid, i, j);
//                     cnt++;
//                 }
//             }
//         }
//         return cnt;
//     }
    
//     void dfs(vector<vector<char>>& grid, int x, int y){
//         grid[x][y] = '0';
//         for(int i = 0; i < 4; i++)
//         {
//             int nx = x + cx[i];
//             int ny = y + cy[i];
//             if(nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == '1')
//             {
//                 dfs(grid, nx, ny);
//             }
//         }
//     }
// };