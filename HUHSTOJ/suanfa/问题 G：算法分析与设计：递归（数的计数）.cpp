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

int f(int n, unordered_map<int, int>& dp)
{
	if(n == 1)
		return 1;
	if(dp[n])
		return dp[n];

	int sum = 1;
	for(int i = 1; i <= n/2; i++)
		sum += f(i, dp);

	dp[n] = sum;
	return sum;
}
int main()
{
	int n;
	while (cin >> n)
	{
		unordered_map<int, int> dp;
		cout << f(n, dp) << endl;
	}
	
	return 0;
}
