class Solution {
    public:
        bool validateBookSequences(vector<int>& putIn, vector<int>& takeOut) {
            stack<int> s;
            int idx = 0;
            for(auto it : putIn)
            {
                s.emplace(it);
                while(!s.empty() && s.top() == takeOut[idx])
                {
                    s.pop();
                    idx++;
                }
            }
            return s.empty();
        }
    };