class Solution {
    public:
        int dismantlingAction(string arr) {
            unordered_set<char> uset;
            int res = 0, l = 0;
            for(int r = 0; r < arr.length(); r++)
            {
                char c = arr[r];
                while(uset.count(c))
                {
                    uset.erase(arr[l++]);
                }
                uset.emplace(c);
                res = max(res, r-l+1);
            }
            return res;
        }
    };