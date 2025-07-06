class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> p_cnt;
        for(char c : p)
            p_cnt[c]++;
        int len = p.length();
        int l = 0, r = 0;
        while(r < s.length())
        {
            char c = s[r];
            p_cnt[c]--;
            r++;
            while(p_cnt[c] < 0)
            {
                p_cnt[s[l]]++;
                l++;
            }
            if(r - l >= len)
                res.emplace_back(l);
        }
        return res;
    }
};