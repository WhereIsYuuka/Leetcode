class Solution {
public:
    string reverseMessage(string message) {
        vector<string> strs;
        int l = 0, r = 0;
        while(r < message.length())
        {
            while(message[r] == ' ' && r < message.length())
                r++;
            if(r >= message.length())
                break;
            l = r;
            while(message[r] != ' ' && r < message.length())
                r++;
            strs.emplace_back(message.substr(l, r - l));
        }
        string res = "";
        for(int i = strs.size() - 1; i >= 0; i--)
        {
            res.append(strs[i]);
            if(i != 0)
                res.push_back(' ');
        }
        return res;
    }
};