class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int res = INT_MIN;
        vector<int> dp(n+1, 0);
        for(int i = 1; i <= n; i++)
        {
            dp[i] = max(nums[i-1], dp[i-1] + nums[i-1]);
        }
        for(int i = 1; i <= n; i++)
        {
            res = max(res, dp[i]);
        }
        return res;
    }
};