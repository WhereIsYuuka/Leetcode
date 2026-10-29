class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        while(l < r)
        {
            int mid = l + (r - l) / 2;
            if(nums[mid] > nums[r])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return nums[l];
    }
};

// class Solution {
// public:
//     int findMin(vector<int>& nums) {
//         int num = nums[0];
//         int l = 0, r = nums.size() - 1;
//         int mid;
//         while (l <= r) {
//             mid = l + (r - l) / 2;
//             num = min(num, nums[mid]);
//             if (nums[mid] < nums[r]) 
//                 r = mid - 1;
//             else 
//                 l = mid + 1;
//         }
//         return num;
//     }
// };