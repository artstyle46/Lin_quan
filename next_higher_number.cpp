#include <bits/stdc++.h>

using namespace std;

int next_numb(int number)
{
	int arr[20];
	int k = 0;
	while(number)
	{
		arr[k++] = number%10;
		number = number/10;
	}
	int temp = 0;
	for(int i = 0; i < k-1; i++)
	{
		if(arr[i] > arr[i + 1])
		{
			temp = arr[i];
			arr[i] = arr[i+1];
			arr[i+1] = temp;
			break;
		}
	}
	number = 0;
	for(int i = 0; i < k; i++)
	{
		number = number + pow(10,i)*arr[i];
	}
	return number;
}

int main()
{
	int number;
	cin >> number;
	cout << next_numb(number) << endl;
	return 0;
}