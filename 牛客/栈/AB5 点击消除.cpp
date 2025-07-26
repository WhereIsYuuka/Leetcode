#include <iostream>
#include <vector>
using namespace std;

int main() {
    string str;
    char res = '0';
    vector<char> stk;
    cin >> str;
    int n = str.length();
    for(int i = 0; i < n; i++)
    {
        if(!stk.empty() && stk.back() == str[i])
        {
            stk.pop_back();
            continue;
        }
        stk.emplace_back(str[i]);
    }
    if(stk.empty())
        cout << res;
    for(auto ch : stk)
        cout << ch;
}
// 64 位输出请用 printf("%lld")