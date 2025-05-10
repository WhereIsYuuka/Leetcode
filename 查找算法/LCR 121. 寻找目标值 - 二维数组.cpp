class Solution {
public:
    bool findTargetIn2DPlants(vector<vector<int>>& plants, int target) {
        if(plants.size() == 0)
            return false;
        int x = 0, y = plants[0].size() - 1;
        while(x < plants.size() && y < plants[0].size())
        {
            if(plants[x][y] < target)
            {
                x++;
            }
            else if(plants[x][y] > target)
            {
                y--;
            }
            else 
                return true;
        }
        return false;
    }
};