#include<iostream>
#include<unordered_map>
#include<stack>

using namespace std;

void CalculateMatrix()
{
    int n;
    unordered_map<char, pair<int, int>> matrix;
    cin >> n;
    while(n--)
    {
        char ch;
        int a, b;
        cin >> ch >> a >> b;
        matrix[ch] = make_pair(a, b);
        // cout << ch << " " << a << " " << b << endl;
    }
    string str;
    cin >> str;
    stack<int> stk;
    int res = 0;
    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == '(')
            continue;
        if(str[i] == ')')
        {
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();
            int c = stk.top();
            stk.pop();
            res += a*b*c;
            stk.push(c);
            stk.push(a);
        }
        else
        {
            stk.push(matrix[str[i]].first);
            stk.push(matrix[str[i]].second);
        }
    }
    cout << res << endl;
}

int main()
{
    CalculateMatrix();
    return 0;
}