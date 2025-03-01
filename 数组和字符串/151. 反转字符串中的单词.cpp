class Solution {
public:
    string reverseWords(string s) {
        // stringstream 用于从string中读取数据
        stringstream ss(s);
        vector<string> words;
        string word;
        while(ss >> word)
            words.push_back(word);
        reverse(words.begin(), words.end());
        string res;
        for(auto word : words)
            res += word + " ";
        // 去掉最后一个空格
        res.pop_back();
        return res;
    }
};