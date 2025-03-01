class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int l = 0, r = matrix[0].size()-1, up = 0, down = matrix.size()-1;
        while(l < r)
        {
            for(int i = 0; i < r-l; i++)
            {
                int tmp = matrix[up][l+i];
                matrix[up][l+i] = matrix[down-i][l];
                matrix[down-i][l] = matrix[down][r-i];
                matrix[down][r-i] = matrix[up+i][r];
                matrix[up+i][r] = tmp;
            }
            l++, r--, up++, down--;
        }
    }
};