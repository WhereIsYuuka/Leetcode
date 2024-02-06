class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> res1;
        unordered_map<string, char> res2;
        stringstream ss(s);
        string tmp;
        for(char c : pattern)
        {
            if(!(ss >> tmp))
                return false;
            if(res1.count(c) && res1[c] != tmp)
                return false;
            if(res2.count(tmp) && res2[tmp] != c)
                return false;
            res1[c] = tmp;
            res2[tmp] = c;
        }
        return !(ss >> tmp);
    }
};