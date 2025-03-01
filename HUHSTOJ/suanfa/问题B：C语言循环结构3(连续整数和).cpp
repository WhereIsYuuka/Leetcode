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
	cin >> n;
	if(n%2 ==0)
		cout << (n/2)*(n+1);
	else
		cout << (n+1)/2*n;

	return 0;
}

