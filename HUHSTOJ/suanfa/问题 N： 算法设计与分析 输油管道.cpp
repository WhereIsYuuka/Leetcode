#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<string>
#include<cstring>
#include<list>
#include<stdlib.h>
using namespace std;
typedef int status;
typedef int selemtype;

void Run(vector<int>& nums, int n)
{
    int res = 0;
    sort(nums.begin(), nums.end());
    for(int i = 0; i < n; i++)
    {
        res += (int)fabs(nums[i] - nums[n/2]);
    }
    cout << res << endl;

}

int main()
{
    int n, tmp;
    cin >> n;
    vector<int> nums(n);

    for(int i = 0; i < n; i++)
        cin >> tmp >> nums[i];

    Run(nums, n);
    return 0;
}
