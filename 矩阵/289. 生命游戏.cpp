class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        int dir[3] = {0, 1, -1};

        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                int live = 0;
                for(int i = 0; i < 3; i++)
                {
                    for(int j = 0; j < 3; j++)
                    {
                        if(dir[i] == 0 && dir[j] == 0) continue;
                        int r = row + dir[i];
                        int c = col + dir[j];
                        if(r >= 0 && r < m && c >= 0 && c < n && abs(board[r][c]) == 1)
                        {
                            live++;
                        }
                    }
                }
                if(board[row][col] == 1 && (live < 2 || live > 3))
                {
                    board[row][col] = -1;
                }
                if(board[row][col] == 0 && live == 3)
                {
                    board[row][col] = 2;
                }
            }
        }

        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(board[row][col] > 0)
                {
                    board[row][col] = 1;
                }
                else
                {
                    board[row][col] = 0;
                }
            }
        }
    }
};

// class Solution {
// public:
//     void gameOfLife(vector<vector<int>>& board) {
//         int m = board.size(), n = board[0].size();
//         int dir[] = {-1, 0, 1};

//         for(int row = 0; row < m; row++)
//         {
//             for(int col = 0; col < n; col++)
//             {
//                 int live = 0;
//                 for(int i = 0; i < 3; i++)
//                 {
//                     for(int j = 0; j < 3; j++)
//                     {
//                         if(dir[i] == 0 && dir[j] == 0)
//                             continue;
//                         int r = row + dir[i];
//                         int c = col + dir[j];
//                         if(r>=0 && r<m && c>=0 && c<n && abs(board[r][c]) == 1)
//                             live++;
//                     }
//                 }
//                 if(board[row][col] == 0 && live == 3)
//                     board[row][col] = 2;
//                 if(board[row][col] == 1 && (live < 2 || live > 3))
//                     board[row][col] = -1;
//             }
//         }

//         for(int row = 0; row < m; row++)
//         {
//             for(int col = 0; col < n; col++)
//             {
//                 if(board[row][col] > 0)
//                     board[row][col] = 1;
//                 else
//                     board[row][col] = 0;
//             }
//         }
//     }
// };