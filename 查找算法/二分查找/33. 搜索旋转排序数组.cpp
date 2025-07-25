class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[mid] > nums[r]) l = mid + 1;
            else r = mid;
        }
        int rot = l;
        l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + r >> 1;
            int realmid = (mid + rot) % n;
            if (nums[realmid] == target) return realmid;
            if (nums[realmid] < target) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
};

// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int len = nums.size();
//         if(len == 0)
//             return -1;
//         int l = 0, r = len -1;
//         while(l < r)
//         {
//             int mid = l + (r - l) / 2;
//             if(nums[mid] > nums[r])
//                 l = mid + 1;
//             else
//                 r = mid;
//         }
//         int offset = l;
//         l = 0, r = len - 1;
//         while(l <= r)
//         {
//             int mid = l + (r - l) / 2;
//             int relMid = (mid + offset) % len;
//             if(nums[relMid] == target)
//                 return relMid;
//             if(nums[relMid] < target)
//                 l = mid + 1;
//             else
//                 r = mid - 1;
//         }
//         return -1;
//     }
// };