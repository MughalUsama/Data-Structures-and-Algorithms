#include<iostream>
#include<fstream>
using namespace std;
void takeInputFromFile(int * arr) {
	ifstream fin("input.txt");
	char character;
	for (int i = 0; i < 36; i = i + 1)
	{
		fin >> character;
		arr[i] = (int)character - 48;
	}
	fin.close();
}
void getGlassSum( int * arr , int * glasesInfo) {
	
	int index = 0 , index2 = 0  , sum = 0;
	while (index < 22) {
		for (int i = 0; i < 4; i = i + 1) {
			sum = 0;
			sum = sum + arr[index] + arr[index + 1] + arr[index + 2] + arr[index + 7]
				+ arr[index + 12] + arr[index + 13] + arr[index + 14];
			glasesInfo[index2] = sum;
			index2 = index2 + 1;
			index = index + 1;
		}
		index = index + 2;
	}
}
int getMaxSumIndex(int * glassInfo) {
	int maxSumInd = 0;
	for (int i = 1; i < 16; i = i + 1) {
		if (glassInfo[i] > glassInfo[maxSumInd])
			maxSumInd = i;
	}
	return maxSumInd;
}
void displayGlass(int indexOfMaxSum , int * arr) {
	if (indexOfMaxSum >= 4 && indexOfMaxSum <= 7)
		indexOfMaxSum = indexOfMaxSum + 2;
	else if (indexOfMaxSum >= 8 && indexOfMaxSum <= 11)
		indexOfMaxSum = indexOfMaxSum + 4;
	else if (indexOfMaxSum >= 12 && indexOfMaxSum <=15)
		indexOfMaxSum = indexOfMaxSum + 6;
		
	cout << arr[indexOfMaxSum] << " " << arr[indexOfMaxSum + 1] << " " << arr[indexOfMaxSum + 2] << "\n"
		<< "  " << arr[indexOfMaxSum + 7] << "\n" << arr[indexOfMaxSum + 12] << " " << arr[indexOfMaxSum + 13]
		<< " "<< arr[indexOfMaxSum+14] << "\n";
}

void setElement(int row, int col, int element ,int * arr) {
	if (row < 0 || col < 0 || row >= 6 || col >= 6)
		throw "Not in Range...\n";
	else
		arr[row * 6 + col] = element;
}
int getElement(int row, int col, int * arr) {
	if (row < 0 || col < 0 || row >= 6 || col >= 6)
		throw "Not in Range...\n";
	else
		return arr[row * 6 + col];
}
int main()
{
	int * array = new int[36];
    int * glassInfo = new int[16];
	takeInputFromFile(array);
	int ind = 1;
	for (int i = 0; i < 36; i = i + 1)
	{
		cout<<array[i]<<" ";
		if (ind == 6)
		{
			cout << "\n";
			ind = 1;
		}
		else
			ind++;
	}
	getGlassSum(array, glassInfo);
	int maxSumIndex = getMaxSumIndex(glassInfo);
	cout <<maxSumIndex<< "Maximum Sum : " << glassInfo[maxSumIndex]<<"\n\n";
	displayGlass(maxSumIndex, array);
	cout << "\n\n\n";
	return 0;
}