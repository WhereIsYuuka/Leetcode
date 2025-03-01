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


int main ()
{
	int n;
	while(cin >> n){
		long res;
		int pre = 1, cur = 1;
		for(int i = 3; i <= n; i++)
		{
			res = pre + cur;
			pre = cur;
			cur = res;
		}
		cout << res << endl;
	}
}

