class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int cnt = 0, res = 0;
        int n = grid.size(), m = grid[0].size();
        int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
        queue<pair<int, int>> que;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                    cnt++;
                else if(grid[i][j] == 2)
                {
                    que.push({i, j});
                }
            }
        }
        while(cnt && !que.empty())
        {
            res++;
            int queCnt = que.size();
            for(int j = 0; j < queCnt; j++)
            {
                int _x = que.front().first, _y = que.front().second;
                que.pop();
                for(int i = 0; i < 4; i++)
                {
                    int _newX = _x + dx[i], _newY = _y + dy[i];
                    if(_newX >= 0 && _newX < n && _newY < m && _newY >= 0 && grid[_newX][_newY] == 1)
                    {
                        grid[_newX][_newY] = 2;
                        cnt--;
                        que.push({_newX, _newY});
                    }
                }
            }
        }
        return cnt > 0 ? -1 : res;
    }
};