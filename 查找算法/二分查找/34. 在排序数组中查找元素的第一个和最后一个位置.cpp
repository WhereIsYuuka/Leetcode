class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if(n < 1)
            return{-1, -1};
        auto findLeft = [&](this auto&& findLeft, int l, int r, int _target) -> int {
            while(l < r)
            {
                int mid = l + (r - l) / 2;
                if(nums[mid] >= _target)
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            return l;
        };

        int lIdx = findLeft(0, n, target);
        int rIdx = findLeft(0, n, target+1) -1;
        if(lIdx <= rIdx)
            return {lIdx, rIdx};
        return {-1, -1};
    }
};

// class Solution {
// public:
//     vector<int> searchRange(vector<int>& nums, int target) {
//         int left = Search(nums, target);
//         int right = Search(nums, target + 1) - 1;
//         if(left <= right)
//             return {left, right};
//         return {-1, -1};
//     }

//     int Search(vector<int>& nums, int target)
//     {
//         int left = 0, right = nums.size() - 1;
//         while(left <= right)
//         {
//             int mid = left + (right - left) / 2;
//             if(nums[mid] >= target)
//                 right = mid - 1;
//             else
//                 left = mid + 1;
            
//         }
//         return left;
//     }
// };