class Solution {
public:
    int jump(vector<int>& nums) {
        int res = 0;
        int curRight = 0, nextRight = 0;
        for(int i = 0; i < nums.size() - 1; i++)
        {
            nextRight = max(nextRight, i + nums[i]);
            if(i == curRight)
            {
                curRight = nextRight;
                res++;
            }
        }
        return res;
    }
};