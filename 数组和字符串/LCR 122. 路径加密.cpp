class Solution {
    public:
        string pathEncryption(string path) {
            string res = "";
            for(auto& it : path)
            {
                if(it == '.')
                    res += ' ';
                else
                    res += it;
            }
            return res;
        }
    };