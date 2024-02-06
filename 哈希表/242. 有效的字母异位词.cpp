class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;
        for(auto c : s)
            m[c]++;
        for(auto c : t)
            m[c]--;
        for(auto it = m.begin(); it != m.end(); it++)  
            if(it->second != 0)
                return false;
        return true;
    }
};

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         vector<int> s1, s2;
//         for(auto it : s)    s1.push_back(it);
//         for(auto it : t)    s2.push_back(it);
//         sort(s1.begin(), s1.end());
//         sort(s2.begin(), s2.end());
//         if(s1 == s2)
//             return true;
//         return false;
//     }
// };