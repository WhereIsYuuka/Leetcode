class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0, l = -1;
        heights.emplace_back(-1);
        stack<int> stk;
        for(int i = 0; i < heights.size(); i++)
        {
            while(!stk.empty() && heights[stk.top()] > heights[i])
            {
                int idx = stk.top();
                stk.pop();
                if(stk.empty())
                {
                    l = -1;
                }
                else
                {
                    l = stk.top();
                }
                res = max(res, (i - l - 1) * heights[idx]);
            }
            stk.push(i);
        }
        return res;
    }
};