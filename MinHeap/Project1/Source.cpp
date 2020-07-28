#include <iostream>
using namespace std;



void swapValues(int& x, int& y);

void heapify(int arr[], int i, int length);
void buildMinHeap(int arr[], int length)
{
	for (int i = (length-1)/2; i >= 0 ; i--)
	{
		heapify(arr, i,length);
	}
}
void heapify(int arr[],int i, int length)
{
	for (int j=i; j < length; j++)
	{
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		int smallest = i;
		if (l < length && arr[l] < arr[i])
		{
			smallest = l;
		}
		if (r < length && arr[r] < arr[smallest])
		{
			smallest = r;
		}
		if (smallest != i)
		{
			swapValues(arr[i], arr[smallest]);
			heapify(arr, smallest, length);
		}
	}
}

void swapValues(int& x, int& y)
{
	int temp = x;
	x = y;
	y = temp;
}

void sortArray(int arr[], int length)
{
	int len = length;
	for (int i = 0; i < length; i++)
	{
	
		heapify(arr, i, length);
	}
	cout << "\n";
	
}
void display(int arr[], int length)
{
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}
int main()
{
	int arr[10] = { 16,14,10,8,7,9,3,2,4,1 };
	
	cout << "Unsorted \n";
	display(arr, 10);
	cout << "\n";
	buildMinHeap(arr, 10);
	cout << "\n";
	cout << "Heaped \n";
	display(arr, 10);
	sortArray(arr, 10);
	cout << "Sorted \n";
	display(arr, 10);
	cout << "\n";
	return 0;
}
