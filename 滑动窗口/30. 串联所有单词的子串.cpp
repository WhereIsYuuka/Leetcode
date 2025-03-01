class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if(words.empty()) return res;
        int n = s.size(), m = words.size(), len = words[0].size();
        unordered_map<string, int> wordCnt;
        for(auto& word : words) 
            wordCnt[word]++;
        for(int i = 0; i < len; i++)
        {
            int left = i, right = i, cnt = 0;
            unordered_map<string, int> window;
            while(right + len <= n)
            {
                string word = s.substr(right, len);
                right += len;
                if(wordCnt.count(word))
                {
                    window[word]++;
                    cnt++;
                    while(window[word] > wordCnt[word])
                    {
                        string leftWord = s.substr(left, len);
                        left += len;
                        window[leftWord]--;
                        cnt--;
                    }
                    if(cnt == m)
                    {
                        res.push_back(left);
                        string leftWord = s.substr(left, len);
                        window[leftWord]--;
                        left += len;
                        cnt--;
                    }
                }
                else
                {
                    window.clear();
                    cnt = 0;
                    left = right;
                }
            }
        }
        return res;
    }
};