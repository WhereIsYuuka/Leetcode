class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRow = false, firstCol = false;
        for(int i = 0; i < matrix.size(); i++)
        {
            if(matrix[i][0] == 0)
            {
                firstCol = true;
                break;
            }
        }
        for(int i = 0; i < matrix[0].size(); i++)
        {
            if(matrix[0][i] == 0)
            {
                firstRow = true;
                break;
            }
        }
        for(int i = 1; i < matrix.size(); i++)
        {
            for(int j = 1; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0; 
                }
            }
        }
        for(int i = 1; i < matrix.size(); i++)
        {
            if(matrix[i][0] == 0)
            {
                for(int j = 1; j < matrix[0].size(); j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        for(int i = 1; i < matrix[0].size(); i++)
        {
            if(matrix[0][i] == 0)
            {
                for(int j = 1; j < matrix.size(); j++)
                {
                    matrix[j][i] = 0;
                }
            }
        }
        if(firstRow)
        {
            for(int i = 0; i < matrix[0].size(); i++)
            {
                matrix[0][i] = 0;
            }
        }
        if(firstCol)
        {
            for(int i = 0; i < matrix.size(); i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         if(!matrix.size())
//             return;
//         int row = matrix.size();
//         int col = matrix[0].size();
//         bool isRowZero = false, isColZero =false;

//         for(int i = 0; i < row; i++)
//         {
//             for(int j = 0; j < col; j++)
//             {
//                 if(0 == matrix[i][j])
//                 {
//                     if(0 == i)
//                         isRowZero = true;
//                     if(0 == j)
//                         isColZero = true;
//                     matrix[i][0] = 0;
//                     matrix[0][j] = 0;
//                 }
//             }
//         }

//         for(int i = 1; i < row; i++)
//         {
//             for(int j = 1; j < col; j++)
//             {
//                 if(0 == matrix[0][j] || 0 == matrix[i][0])
//                     matrix[i][j] = 0;
//             }
//         }

//         if(isRowZero)
//             for(int i = 0; i < col; i++)
//                 matrix[0][i] = 0;
        
//         if(isColZero)
//             for(int i = 0; i < row; i++)
//                 matrix[i][0] = 0;
//     }
// };