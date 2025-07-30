class Solution {
public:
    int circleGame(vector<vector<int>>& toys, vector<vector<int>>& circles, int r) {
        int res = 0;
        for(auto& toy : toys)
        {
            int tx = toy[0], ty = toy[1], tr = toy[2];
            if(tr > r)
                continue;
            bool isCover = false;
            for(auto& circle : circles)
            {
                int cx = circle[0], cy = circle[1];
                long dx = tx - cx, dy = ty - cy;
                long dis = dx * dx + dy * dy;
                long maxDis = r - tr;
                if(dis <= maxDis * maxDis)
                {
                    isCover = true;
                    break;
                }
            }
            if(isCover)
                res++;
        }
        return res;
    }
};