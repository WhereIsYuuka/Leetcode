class Solution {
    public:
        string crackPassword(vector<int>& password) {
            vector<string> strs;
            string res;
            for(auto str : password)
            {
                strs.emplace_back(to_string(str));
            }
            sort(strs.begin(), strs.end(), [](const string &str1, const string &str2)
            {
                return str1 + str2 < str2 + str1;
            });
            for(auto str : strs)
            {
                res += str;
            }
            return res;
        }
    };