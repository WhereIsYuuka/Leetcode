class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l = 0, r = 0, tmp;
        for(int i = 0; i < nums.size(); i++)
        {
            tmp = nums[i];
            nums[i] = 2;
            if(tmp <= 1)
            {
                nums[r++] = 1;
            }
            if(tmp == 0)
            {
                nums[l++] = 0;
            }
        }
    }
};