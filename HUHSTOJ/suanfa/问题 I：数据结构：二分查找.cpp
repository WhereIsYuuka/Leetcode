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

void Run(int n)
{
	int target;
	vector<int> nums(n+1);
	for(int i = 0; i < n; i++)
		cin >> nums[i];
	cin >> target;
	
	int l = 0, r = n-1;
	while(l <= r)
	{
		int mid = l + (r - l)/2;
		if(target == nums[mid])
		{
			cout << mid+1 << endl;
			return;
		}
		else if(target > nums[mid])
			l = mid + 1;
		else	
			r = mid - 1;
	}
	cout << "No found!" << endl;
}

int main ()
{
	int n;
	while(cin >> n){
		Run(n);
	}
	return 0;
}

