class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = Search(nums, target);
        int right = Search(nums, target + 1) - 1;
        if(left <= right)
            return {left, right};
        return {-1, -1};
    }

    int Search(vector<int>& nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target)
                right = mid - 1;
            else
                left = mid + 1;
            
        }
        return left;
    }
};