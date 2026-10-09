class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        slow = nums[slow];
        fast = nums[nums[fast]];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        int head = 0;
        while(head != slow)
        {
            head = nums[head];
            slow = nums[slow];

        }
        return slow;
    }
};