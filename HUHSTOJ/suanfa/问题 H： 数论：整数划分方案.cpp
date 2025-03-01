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
#include<unordered_map>
using namespace std;
typedef int status;
typedef int selemtype;

int Run(int n)
{
	vector< vector<int>> dp(n+1, vector<int>(n+1, 0));
	for(int i = 0; i <= n; i++)
		dp[0][i] = 1;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(i >= j)
			{
				dp[i][j] = dp[i-j][j] + dp[i][j-1];
			}
			else
			{
				dp[i][j] = dp[i][j-1];
			}
		}
	}
	return dp[n][n];
}

int main ()
{
	int n;
	while(cin >> n)
	{
		cout << Run(n) << endl;
	}
	return 0;
}
