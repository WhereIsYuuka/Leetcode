class Solution {
    public:
        vector<int> maxAltitude(vector<int>& heights, int limit) {
            vector<int> res;
            deque<int> deq;
            for(int i = 0; i < heights.size(); i++)
            {
                while(!deq.empty() && heights[deq.back()] <= heights[i])
                    deq.pop_back();
                deq.emplace_back(i);
                if(i - deq.front() >= limit)
                    deq.pop_front();
                if(i >= limit - 1)
                    res.emplace_back(heights[deq.front()]);
            }
            return res;
        }
    };