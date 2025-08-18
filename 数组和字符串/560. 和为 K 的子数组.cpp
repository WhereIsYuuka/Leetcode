class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        if(n < 1)
            return 0;
        int res = 0;
        vector<int> sum(n+1);
        for(int i = 0; i < n; i++)
        {
            sum[i+1] = sum[i] + nums[i]; 
        }

        unordered_map<int, int> cnt;
        for(auto num : sum)
        {
            res += cnt.contains(num - k) ? cnt[num - k] : 0;
            cnt[num]++;
        }
        return res;
    }
};