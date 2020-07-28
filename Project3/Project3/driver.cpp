#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

bool binarySearch(int *arr, int size, int key)
{
		
	int start = 0, end = size-1, mid;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (arr[mid] == key)
		{
			return true;
		}
		else if (key > mid)
		{
			start = mid + 1;
		}
		else
		{
			end = mid - 1;
		}
	}
	return false;

}

int main()

{
	int arr[3] = { 1,2,3 };
	
	cout << "\n";
	cout << binarySearch(arr, 3, 3);
	system("pause");
	return 0;

}
