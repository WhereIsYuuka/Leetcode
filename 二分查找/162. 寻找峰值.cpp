class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        int l = 0, r = len -1;
        while(l < r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};