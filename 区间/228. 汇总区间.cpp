class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        if(nums.size() == 0)
            return res;
        int l = nums[0];
        int r = nums[0];
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] == r + 1)
            {
                r = nums[i];
            }
            else
            {
                if(r == l)
                {
                    res.push_back(to_string(l));
                }
                else
                {
                    res.push_back(to_string(l) + "->" + to_string(r));
                }
                l = nums[i];
                r = nums[i];
            }
        }
        if(r == l)
        {
            res.push_back(to_string(l));
        }
        else
        {
            res.push_back(to_string(l) + "->" + to_string(r));
        }
        return res;
    }
};