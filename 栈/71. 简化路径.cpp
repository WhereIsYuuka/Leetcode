class Solution {
public:
    string simplifyPath(string path) {
        vector<string> tmp;
        string res, t;
        stringstream ss(path);
        while(getline(ss, t, '/'))
        {
            if(t == "" || t == ".")
                continue;
            if(t == ".." && !tmp.empty())
                tmp.pop_back(); 
            else if(t != "..")
                tmp.push_back(t);
        }
        for(string& s : tmp)
        {
            res += "/" + s;
        }
        return res.empty() ? "/" : res;
    }
};

// class Solution {
// public:
//     string simplifyPath(string path) {
//         vector<string> tmp;
//         string res, str;
//         stringstream ss(path);
//         while(getline(ss, str, '/'))    //以/为分隔
//         {
//             if(str == "." || str == "")
//                 continue;
//             if(str == ".." && !tmp.empty())
//                 tmp.pop_back();
//             else if(str != "..")
//                 tmp.push_back(str);
//         }
//         for(auto &s : tmp)
//         {
//             res += ('/' + s);
//         }
//         if(!res.length())
//         {
//             return "/";
//         }
//         return res;
//     }
// };