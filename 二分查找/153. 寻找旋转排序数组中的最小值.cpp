class Solution {
public:
    int findMin(vector<int>& nums) {
        int num = nums[0];
        int l = 0, r = nums.size() - 1;
        int mid;
        while (l <= r) {
            mid = l + (r - l) / 2;
            num = min(num, nums[mid]);
            if (nums[mid] < nums[r]) 
                r = mid - 1;
            else 
                l = mid + 1;
        }
        return num;
    }
};