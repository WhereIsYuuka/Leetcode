class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if(n == 0 || m == 0 || n < m)
            return "";
        unordered_map<char, int> need, window;
        int left = 0, right = 0;
        int vaild = 0, start = 0, len = INT_MAX;
        for(char c :t)
            need[c]++;
        while(right < n)
        {
            char c = s[right++];
            if(need.count(c))
            {
                window[c]++;
                if(window[c] == need[c])
                    vaild++;
            }
            while(vaild == need.size())
            {
                if(right - left < len)
                {
                    start = left;
                    len = right - left;
                }
                char d = s[left++];
                if(need.count(d))
                {
                    window[d]--;
                    if(window[d] < need[d])
                        vaild--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};