#include <bits/stdc++.h>

using namespace std;

struct point {
	int first;
	int last;
};

struct point* max_sum_indices(int arr[], int n)
{
	int sum_current = 0;
	int max_sum = 0;
	struct point *indices;
	indices->first = 0;
	indices->last = 0;
	for(int i =0; i <n; i++)
	{
		sum_current+= arr[i];
		if(sum_current > max_sum)
		{
			max_sum = sum_current;
			indices->last = i;
		}
		if(sum_current <= 0)
		{
			sum_current = 0;
			indices->first = i+1;
		}
	}
	return indices;
}

int main()
{
//	int arr[8] = {-3,4,-5,6,9,-2,-3,1};
	int arr1[9] = {-2,1,-3,4,-1,2,1,-5,4};
	struct point *indices;
	indices = max_sum_indices(arr1,9);
	cout << indices->first << "-" << indices->last << endl;
	return 0;
}