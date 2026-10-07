class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> ump;
        for(auto it : strs)
        {
            string tmp = it;
            sort(tmp.begin(), tmp.end());
            ump[tmp].emplace_back(it);
            
        }
        for(auto it : ump)
            res.emplace_back(it.second);
        return res;
    }
};

// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> mp;
//         for(auto it : strs)
//         {
//             string tmp = it;
//             sort(tmp.begin(), tmp.end());
//             mp[tmp].push_back(it);
//         }
//         vector<vector<string>> res;
//         for(auto it : mp)
//         {
//             res.push_back(it.second);
//         }
//         return res;
//     }
// };