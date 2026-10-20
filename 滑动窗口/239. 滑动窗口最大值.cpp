#include<vector>
#include<deque>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res(nums.size() - k + 1);
        deque<int> maxQue;
        for(int i = 0; i < nums.size(); i++)
        {
            while(!maxQue.empty() && nums[maxQue.back()] <= nums[i])
            {
                maxQue.pop_back();
            }
            maxQue.push_back(i);
            int l = i - k + 1;
            if(maxQue.front() < l)
                maxQue.pop_front();

            if(l >= 0)
                res[l] = nums[maxQue.front()];
        }
        return res;
    }
};