class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int lMax = 0, rMax = 0 ,res = 0;
        while(l < r)
        {
            lMax = max(lMax, height[l]);
            rMax = max(rMax, height[r]);
            if(lMax < rMax)
            {
                res += (lMax - height[l]);
                l++;
            }
            else
            {
                res += (rMax - height[r]);
                r--;
            }
        }
        return res;
    }
};