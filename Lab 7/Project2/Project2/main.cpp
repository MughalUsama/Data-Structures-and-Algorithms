#include <iostream>
using namespace std;

void calcMaxValue(int *weight,int *value,int noOfitems,int maxCapacity,int &maxVal,int presentWeight,int presentVal)
{
	if (presentVal>maxVal && presentWeight <= maxCapacity)
	{
		maxVal = presentVal;
	}
	for (int i = 0; i < noOfitems; i++)
	{
		if ((presentWeight + weight[i]) <= maxCapacity)
		{
			presentWeight = presentWeight + weight[i];
			presentVal = presentVal + value[i];
			calcMaxValue((weight+1), (value +1), noOfitems - 1, maxCapacity, maxVal, presentWeight, presentVal);

			presentWeight = presentWeight - weight[i];
			presentVal = presentVal - value[i];
		}
	}
}

int main()
{
	int testCases;
	cin >> testCases;
	for (int j = 0; j < testCases; j++)
	{
		int noOfItems, maxCapacity, maxValue = 0, presentWeight = 0, presentVal = 0;
		cin >> noOfItems >> maxCapacity;
		int* weight = new int[noOfItems], *value = new int[noOfItems];
		for (int i = 0; i < noOfItems; i++)
		{
			cin >> weight[i];
		}
		for (int i = 0; i < noOfItems; i++)
		{
			cin >> value[i];
		}
		calcMaxValue(weight, value, noOfItems, maxCapacity, maxValue, presentWeight, presentVal);
		cout << maxValue;

		cout << "\n";
	}
	return 0;
}