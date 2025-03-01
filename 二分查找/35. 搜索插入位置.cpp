class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        if(target > nums[right]) 
            return right + 1;
        if(target < nums[0]) 
            return left;
        while(left < right)
        {
            int mid = (right + left) / 2;
            if(nums[mid] == target) 
                return mid;
            else if(nums[mid] < target) 
                left = mid + 1;
            else 
                right = mid;
        }
        return left;
    }
};