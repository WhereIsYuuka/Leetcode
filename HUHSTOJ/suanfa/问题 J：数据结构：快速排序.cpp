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

void printArray(vector<int>& nums)
{
	for(int i = 0; i < nums.size(); i++)
	{
       cout << nums[i];
       if (i < nums.size() - 1) cout << " ";
	}
	cout << endl;
}

//void quick_sort(vector<int>& nums, int l, int r)
//{
//	if(l >= r)
//		return;
//	
//	int i = l-1, j = r+1, tmp = nums[r];
//	while(i < j)
//	{
//		do i++;	while(nums[i] < tmp);
//		do j--; while(nums[j] > tmp);
//		if(i < j)	
//			swap(nums[i], nums[j]);
//	}
//	
//	printArray(nums);
//	
//	quick_sort(nums, l, j);
//	quick_sort(nums, j+1, r);
//}


void quick_sort(vector<int>& nums, int l, int r)
{
	int i = l, j = r;
	if(i >= j)
		return;
	int tmp = nums[i];
	while(i < j)
	{
		while(nums[j] > tmp && i < j)	j--;
		if(i < j)
			nums[i++] = nums[j];
		while(nums[i] < tmp && i < j)	i++;
		if(i < j)
			nums[j--] = nums[i];

	}
	
	nums[i] = tmp;
	printArray(nums);
	quick_sort(nums, l, i-1);
	quick_sort(nums, i+1, r);

}

int main ()
{
	int n;
	vector<int> nums;
	while(cin >> n)
	{
		nums.push_back(n);
		if(cin.get() == '\n')
			break;
	}
	quick_sort(nums, 0, nums.size()-1);
}
//6 7 8 0 4 3 5 9 1 2
