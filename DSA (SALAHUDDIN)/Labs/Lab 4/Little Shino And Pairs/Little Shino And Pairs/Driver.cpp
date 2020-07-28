#include<iostream>
using namespace std;

int findMax(int * arr , int size) {
	int max = arr[0];
	for (int i = 1; i < size; i = i + 1) {
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
int findSecMax(int * arr, int size , int max) {
	int secMax = arr[0];
	for (int i = 1; i < size; i = i + 1) {
		if ((arr[i] > secMax) && (arr[i] < max)) {
			secMax = arr[i];
		}
		else if (max == secMax) {
			secMax = arr[i];
		}
	}
	return secMax;
}
bool isPairAlreadyExit(int * pair1, int * pair2, int numOfPairs, int max, int secMax) {
	for (int i = 0; i < numOfPairs; i = i + 1) {
		if (pair1[i] == max) {
			if (pair2[i] == secMax)
				return true;
		}
	}
	return false;
}
int possibleSubArraysAndPairs(int * arr, int size) {
	int sizeC1 = size , sizeC2 = size;
	int * pairsA = new int[size-1];
	int * pairsB = new int[size-1];
	int numOfPairs = 0, max, secMax;
	for (int k = 0; k < sizeC1; k = k + 1) {
		for (int i = k; i < sizeC2; sizeC2 = sizeC2 - 1) {
			int subArrSize = sizeC2 - i;
			int * subArr = new int[subArrSize];
			for (int j = i , index = 0; j < sizeC2; j = j + 1 , index = index + 1) {
				subArr[index] = arr[j];
			}
			for (int l = 0; l < subArrSize; l = l + 1) {      //  To See All Possible Arrays
				cout << subArr[l] << " , ";
			}
			cout << "\n";
			max = findMax(subArr, subArrSize);
			secMax = findSecMax(subArr, subArrSize, max);
			if ((isPairAlreadyExit(pairsA, pairsB, numOfPairs, max, secMax) == false)&&(max != secMax)) {
				pairsA[numOfPairs] = max;
				pairsB[numOfPairs] = secMax;
				numOfPairs = numOfPairs + 1;
			}
		}
		sizeC2 = size;
	}
	for (int i = 0; i < numOfPairs; i = i + 1) {                //      To See All Possible Pairs
		cout << "( " << pairsA[i] << " , " << pairsB[i] << " )\n";
	}
	return numOfPairs;
}
int main()
{
	int N;
	do {
		cout << "Do it Man...\n";
		cin >> N;
	} while (N < 1 || N>105);
	int * arr = new int[N];
	bool flag = true;
	for (int i = 0; i < N; i = i + 1) {
		do {
			flag = true;
			cin >> arr[i];
			if (arr[i] <1 || arr[i]>N)
			{
				flag = false;
				cout << "Do it Man2...\n";
			}
		} while (flag == false);
	}
	cout<<possibleSubArraysAndPairs(arr, N);
	cout << "\n\n\n";
	return 0;
}