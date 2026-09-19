class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.length();
        int last[26];
        for(int i = 0; i < n; i++)
        {
            last[s[i] - 'a'] = i;
        }
        vector<int> res;
        int left = 0, right = 0;
        for(int i = 0; i < n; i++)
        {
            right = max(right, last[s[i] - 'a']);
            if(i == right)
            {
                res.emplace_back(right - left + 1);
                left = right + 1;
            }
        }
        return res;
    }
};