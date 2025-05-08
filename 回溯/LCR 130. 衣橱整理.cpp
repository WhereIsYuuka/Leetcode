class Solution {
    private:
        int m, n, cnt;
    
    public:
        int wardrobeFinishing(int m, int n, int cnt) {
            this->m = m, this->n = n, this->cnt = cnt;
            vector<vector<bool>> isVisited(m, vector<bool>(n, false));
            return dfs(0, 0, 0, 0, isVisited);
        }
    
        int dfs(int i, int j, int sumI, int sumJ, vector<vector<bool>> &isVisited)
        {
            if(i >= m || j >= n || (sumI + sumJ) > cnt || isVisited[i][j])
                return 0;
            isVisited[i][j] = true;
            return 1 + dfs(i+1, j, (i+1) % 10 == 0 ? sumI - 8 : sumI + 1, sumJ, isVisited) + dfs(i, j+1, sumI, (j+1) % 10 == 0 ? sumJ - 8 : sumJ + 1, isVisited);
        }
    };