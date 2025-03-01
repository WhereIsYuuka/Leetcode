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
		long res = 0;
		for(int i = 2; i <= n; i+=2)
		{
			res += i;
		}
		cout << res << endl;
	}
	return 0;
}

