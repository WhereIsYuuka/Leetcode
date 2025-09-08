class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int h = matrix.size();
        int w = matrix[0].size()-1;
        int l = 0;
        for(int i = 0; i < h; i++)
        {
            if(matrix[i][w] == target)
                return true;
            if(matrix[i][w] > target)
            {
               l = i;
                break; 
            }
        }
        for(int i = 0; i <= w; i++)
        {
            if(matrix[l][i] == target)
                return true;
        }
        return false;
    }
};

// class Solution {
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int n = matrix.size(), m = matrix[0].size();
//         int l = 0, r = matrix.size() * matrix[0].size() - 1;
//         int mid, tmp;
//         while(l <= r)
//         {
//             mid = l + (r - l) / 2;
//             tmp = matrix[mid / m][mid % m];
//             if(target == tmp)
//                 return true;
//             else if(target < tmp)
//                 r = mid - 1;
//             else
//                 l = mid + 1; 
//         }
//         return false;
//     }
// };