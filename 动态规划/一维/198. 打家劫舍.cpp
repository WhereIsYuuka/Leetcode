class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, 0);
        dp[1] = nums[0];
        for(int i = 1; i < n; i++)
        {
            dp[i+1] = max(dp[i], dp[i-1] + nums[i]);
        }
        return dp[n];
    }
};

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int len = nums.size();
//         switch (len){
//         case 0:
//             return 0;
//             break;
//         case 1:
//             return nums[0];
//             break;
//         case 2:
//             return max(nums[0], nums[1]);
//             break;
//         default:
//             break;
//         }
//         int pre = nums[0], cur = max(nums[0], nums[1]), maxSum = cur;
//         for(int i = 2; i < len; i++)
//         {
//             maxSum = max(pre + nums[i], cur);   //局部最优解 
//             pre = cur;
//             cur = maxSum;
//         }
//         return maxSum;
//     }
// };