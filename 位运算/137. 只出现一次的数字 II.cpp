class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int len = nums.size();
        if(len == 1) return nums[0];
        int res = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i+3 < len; i += 3)
        {
            if(nums[i] != nums[i+1])
            {
                res = nums[i];
                break;
            }
        }
        if(res == 0) res = nums[len-1];
        return res;
    }
};