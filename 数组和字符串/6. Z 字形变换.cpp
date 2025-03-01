class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)    
            return s;
        vector<string> rows(min(numRows, int(s.size())));
        int curRow = 0;
        bool isUP = true;
        string res;

        for(char c : s)
        {
            rows[curRow] += c;
            if(curRow == 0 || curRow == numRows-1)
                isUP = !isUP;
            curRow += isUP ? -1 : 1;
        }
        for(string tmp : rows)
            res += tmp;
            
        return res;
    }
};