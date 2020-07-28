#include<iostream>
#include<fstream>
using namespace std;
void setElement(int row, int col, int element, int * arr , int size) {
	if (row < 0 || col < 0 || row >= size || col >= size)
		throw "Not in Range...\n";
	else
		arr[col * size + row] = element;
}
int getElement(int row, int col, int * arr , int size) {
	if (row < 0 || col < 0 || row >= size || col >= size)
		throw "Not in Range...\n";
	else
		return arr[col * size + row];
}
void takeInputFromFile(int * arr) {
	ifstream fin("input.txt");
	int index = 0, size;
	fin >> size;
	while (!fin.eof()) {
		fin >> arr[index];
		index = index + 1;
	}
	fin.close();
}
int getPrimarySum(int * arr , int size) {
	int sum = 0;
	for (int i = 0; i < size; i = i + 1) {
		for (int j = 0; j < size; j = j + 1) {
			if (i == j)
				sum = sum + arr[(j * size) + i];
		}
	}
	return sum;
}
int getSecondarySum(int * arr, int size) {
	int sum = 0 , sizeC = size;
	for (int i = 0; i < size; i = i + 1) {
		for (int j = 0; j < size; j = j + 1) {
			if (j == (sizeC-1 ))
			{
				sum = sum + arr[(j * size) + i];
			}
		}
		sizeC = sizeC - 1;
	}
	return sum;
}
int main() 
{
	ifstream fin("input.txt");
	int size;
	fin >> size;
	fin.close();
	int * array = new int[size*size];
	takeInputFromFile(array);
	int stop = 0;
	cout << "\n";
	int sum = getPrimarySum(array, size);
	int sum2 = getSecondarySum(array, size);
	cout <<"Primary Sum : "<<sum <<"\nSecondary Sum : " << sum2<<"\n";
	int absolSum = sum - sum2;
	if (absolSum < 0)
		absolSum = absolSum*(-1);
	cout << "Absolute Sum : " << absolSum;
	cout << "\n\n\n";
	return 0;
}