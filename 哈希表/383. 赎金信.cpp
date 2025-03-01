class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int res[26] = {0};
        for(int i = 0; i < magazine.length(); i++)
        {
           res[magazine[i] - 'a']++;
        }
        for(int i = 0; i < ransomNote.length(); i++)
        {
            if(res[ransomNote[i] - 'a'] == 0)
                return false;
            res[ransomNote[i] - 'a']--;
        }
        return true;
    }
};