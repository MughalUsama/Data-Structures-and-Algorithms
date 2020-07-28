#include <iostream>
#include <fstream>

using namespace std;
int getDifference(int *arr, int n);


int main()
{
	int n;
	fstream file("input.txt", ios::in);

	file >> n;
	int * arr = new int[n];

	for (int i = 0; i < n ; i++)
	{
		for (int j = 0; j < n; j++)
		{
			file >> arr[i + j * n];
		}
	}
	cout << "Difference : "  <<getDifference(arr, n);
	cout << "\n";
	return 0;
}


int getDifference(int *arr,int n)
{
	int sumD1 = 0;
	for (int i = 0; i < n; i++)
	{
		sumD1 += arr[i + i * n];
	}
	int sumD2 = 0;
	for (int i = 0; i < n; i++)
	{
		sumD2 += arr[(n - 1) + i * (n - 1)];
	}
	int difference=sumD1 - sumD2;
	if (difference<0)
	{
		return -difference;
	}
	return difference;
	
}