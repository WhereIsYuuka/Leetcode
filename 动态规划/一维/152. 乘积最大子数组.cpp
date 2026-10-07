class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        vector<int> dpMax(n+1);
        vector<int> dpMin(n+1);
        dpMax[0] = dpMin[0] = nums[0];
        for(int i = 1; i < n; i++)
        {
            int num = nums[i];
            dpMax[i] = max(dpMax[i-1] * num, max(dpMin[i-1] * num, num));
            dpMin[i] = min(dpMax[i-1] * num, min(dpMin[i-1] * num, num));
            res = max(dpMax[i], res);
            // cout << dpMax[i] << " -- " <<  dpMin[i] << endl;
        }
        
        return res;
    }
};