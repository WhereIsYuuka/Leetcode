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

void hanoi(int n, char a, char b, char c)
{
	if(n == 1)	
		cout << a << "->" << c << endl;
	else
	{
		hanoi(n-1, a, c, b);
		cout << a << "->" << c << endl;
		hanoi(n-1, b, a, c);
	}
}

int main ()
{
	int n;
	while(cin >> n){
		hanoi(n, 'A', 'B', 'C');
	}
	return 0;
}

