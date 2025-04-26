class Solution {
    public:
        vector<int> trainingPlan(vector<int>& actions) {
            int l = 0, r = actions.size() - 1;
            while(l < r)
            {
                while(actions[l] % 2 != 0 && l < r)
                    l++;
                while(actions[r] % 2 == 0 && l < r)
                    r--;
                swap(actions[l], actions[r]);
            }
            return actions;
        }
    };