#include<iostream>
#include<fstream>
using namespace std;
void swapNumbers(int & firstNum, int & secondNum)
{
	int temp = firstNum;
	firstNum = secondNum;
	secondNum = temp;
}
void ascendingSelectionSorting(int * arr, int size)
{
	int minIndex, minVal;
	for (int lowerInd1 = 0; lowerInd1 < (size - 1); lowerInd1 = lowerInd1 + 1)
	{
		minIndex = lowerInd1;
		minVal = arr[minIndex];
		for (int lowerInd2 = lowerInd1 + 1; lowerInd2 < size; lowerInd2 = lowerInd2 + 1)
		{
			if (arr[minIndex] > arr[lowerInd2])
			{
				minIndex = lowerInd2;
				minVal = arr[minIndex];
			}
		}
		swapNumbers(arr[lowerInd1], arr[minIndex]);
	}
}
int main()
{
	ifstream fin;
	fin.open("Text File.txt");
	int testCases;
	fin >> testCases;
	int noOfEle;
	for (int i = 0; i < testCases; i = i + 1)
	{
		fin >> noOfEle;
		cout << noOfEle << "\n";
		int * array = new int[noOfEle];
		for (int j = 0; j < noOfEle; j = j + 1)
		{
			fin >> array[j];
		}
		int reqEle;
		fin >> reqEle;
		for (int j = 0; j < noOfEle; j = j + 1)
			cout << array[j]<<" ";
		cout <<"\n"<< reqEle << "\n";
		ascendingSelectionSorting(array, noOfEle);
		cout <<"Req Num : " << array[reqEle-1] << "\n\n\n\n";
	}
	fin.close();
	cout << "\n\n\n";
	return 0;
}