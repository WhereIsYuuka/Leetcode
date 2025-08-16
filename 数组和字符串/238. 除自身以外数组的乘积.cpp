class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> sums(n, 1);
        int l = 1, r = 1;
        for(int i = 0; i < n; i++)
        {
            sums[i] *= l, l *= nums[i];
            sums[n - 1 - i] *= r, r *= nums[n - 1 - i];
        }
        return sums;
    }
};