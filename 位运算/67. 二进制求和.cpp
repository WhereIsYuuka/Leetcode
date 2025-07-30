class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int tmp = 0;
        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || tmp) 
        {
            if(i >= 0) tmp += a[i--] - '0';
            if(j >= 0) tmp += b[j--] - '0';
            res = to_string(tmp % 2) + res; //tmp%2是当前位的值
            tmp >>= 1;  //tmp/2是进位
        }
        return res;
    }
};


// class Solution {
// public:
//     string addBinary(string a, string b) {
//         string res;
//         int tmp = 0;
//         int i = a.length()-1, j = b.length()-1;
//         while(i >= 0 || j >= 0 || tmp)
//         {
//             if(i >= 0)
//                 tmp += a[i--] - '0';
//             if(j >= 0)
//                 tmp += b[j--] - '0';
//             res = to_string(tmp % 2) + res;
//             tmp >>= 1;
//         }
//         return res;
//     }
// };