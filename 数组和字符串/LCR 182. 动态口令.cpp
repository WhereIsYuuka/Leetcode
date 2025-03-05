class Solution {
    public:
        string dynamicPassword(string password, int target) {
            string res = "";
            string path1 = password.substr(0, target);
            string path2 = password.substr(target);
            res = path2 + path1;
            return res;
        }
    };