#include <bits/stdc++.h>

using namespace std;

struct point {
	int first;
	int last;
};

int modulu(int n)
{
	if(n < 0)
		return -1 * n;
	return n;
}
//finding indices.
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

//finding sum closest to zero.

struct point* sum_closest_to_zero(int arr[], int n)
{
	map <int, int> m;
	int sum_current = 0;
	int sum_close = 10000;
	struct point *d;
	m.insert(arr[0]) = 0;
	for(int i =1; i < n; i++)
	{
		m.insert(make_pair(+arr[i],i));
	}
	int diff_arr[8],ind_arr[9];
	int temp=0;
	int k = 0,j=0;
	map <int, int> :: iterator it = m.begin();
	while(it != m.end())
	{
		ind_arr[j++] = it->second;
		if(temp != 0)
		{
			arr[k++] = it->first - temp;
		}
		temp = it->first;
		++it;
	}
	int min = 999;
	int min_index;
	for(int i = 0; i <8; i++)
	{
		if(modulu(arr[i]) < modulu(min))
		{
			min = arr[i];
			min_index = i;
		}
	}
	d->first = ind_arr[min_index];
	d->last = ind_arr[min_index+1];
	return d;
}

int main()
{
//	int arr[8] = {-3,4,-5,6,9,-2,-3,1};
	int arr1[9] = {-2,1,-3,4,-1,2,1,-5,4};
	struct point *indices, *indices1;
	//indices = max_sum_indices(arr1,9);
	indices1 = sum_closest_to_zero(arr1,9);
	//cout << indices->first << "-" << indices->last << endl;
	cout << indices1->first << "-" << indices1->last << endl;	
	return 0;
}