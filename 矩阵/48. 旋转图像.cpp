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

// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int tmp, len = matrix.size();
//         for(int i = 0; i < len / 2; i++)
//         {
//             for(int j = 0; j < (len + 1) / 2; j++)
//             {
//                 tmp = matrix[i][j];
//                 matrix[i][j] = matrix[len-1-j][i];
//                 matrix[len-1-j][i] = matrix[len-1-i][len-1-j];
//                 matrix[len-1-i][len-1-j] = matrix[j][len-1-i];
//                 matrix[j][len-1-i] = tmp;
//             }
//         }
//     }
// };
