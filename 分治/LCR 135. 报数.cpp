class Solution {
private:
    vector<int> res;
    void save(string &str)
    {
        int idx = 0;
        while(str[idx] == '0' && idx < str.length())
        {
            idx++;
        }
        if(idx < str.length())
            res.emplace_back(stoi(str.substr(idx)));
    }

public:
    vector<int> countNumbers(int cnt) {
        string str(cnt, '0');
        while(true)
        {
            save(str);
            int i = cnt - 1;
            while(i >= 0 && str[i] == '9')
            {
                str[i] = '0';
                i--;
            }
            if(i < 0)
                break;
            str[i]++;
        }
        return res;
    }
};