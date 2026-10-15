class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums)
        {
            sum += it;
        }
        if(sum % 2 != 0)
            return false;
        sum /= 2;
        int n = nums.size();
        vector<int> dp(10001, 0);
        for(int i = 0; i < n; i++)
        {
            for(int j = sum; j >= nums[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if(dp[sum] == sum)
            return true;
        return false;
    }
};