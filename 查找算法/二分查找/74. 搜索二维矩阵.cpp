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