class Solution {
public:
    char dismantlingAction(string arr) {
        unordered_map<int, int> ump;
        for(auto c : arr)
        {
            ump[c - 'a']++;
        }
        for(auto c : arr)
        {
            if(ump[c - 'a'] == 1)
                return c;
        }
        return ' ';
    }
};