#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, tmp, res = 1;
    cin >> n;
    vector<int> num(n, 0), dp(n+1, 1);
    for(int i = 0; i < n; i++)
    {
        cin >> num[i];
    }

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(num[j] < num[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
        
    }
    cout << res;
}
// 64 位输出请用 printf("%lld")