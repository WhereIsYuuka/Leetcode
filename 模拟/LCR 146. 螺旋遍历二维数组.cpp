class Solution {
    public:
        vector<int> spiralArray(vector<vector<int>>& array) {
            if(array.empty())
                return {};
            vector<int> res;
            int m = array.size(), n = array[0].size();
            int up = 0, down = m - 1, left = 0, right = n - 1;
            while(true)
            {
                for(int i = left; i <= right; i++)
                    res.push_back(array[up][i]);
                if(++up > down)
                    break;
                for(int i = up; i <= down; i++)
                    res.push_back(array[i][right]);
                if(--right < left)
                    break;
                for(int i = right; i >= left; i--)
                    res.push_back(array[down][i]);
                if(--down < up)
                    break;
                for(int i = down; i >= up; i--)
                    res.push_back(array[i][left]);
                if(++left > right)
                    break;
            }
            return res;
        }
    };