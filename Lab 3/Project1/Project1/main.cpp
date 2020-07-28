#include <iostream>
#include <fstream>

using namespace std;
void getMaxHourGlass(int * arr, int rows, int coloumns);

int main()
{
	int arr[36];
	fstream file("input.txt",ios::in);
	
	for (int i = 0; i < 36 && !file.eof(); i++)
	{
		file >> arr[i];
	}

	getMaxHourGlass(arr, 6, 6);
	cout << "\n";
	return 0;
}

void getMaxHourGlass(int * arr, int rows, int coloumns)
{
	int maxSum = 0,sum = 0, maxHourGlass=0, noOfHourGlass = 0;
	while(noOfHourGlass < (rows)*(coloumns) - 1)
	{
		sum = arr[noOfHourGlass] + arr[noOfHourGlass + 1] + arr[noOfHourGlass + 2] + arr[noOfHourGlass + coloumns+1] + arr[noOfHourGlass +2*(coloumns)] + arr[noOfHourGlass + 2*(coloumns)+1] + arr[noOfHourGlass + 2*(coloumns)+2];
		if (sum>maxSum && !(noOfHourGlass%rows > (rows-3)) && !(noOfHourGlass%rows >(coloumns-3)))
		{
			maxSum = sum;
			maxHourGlass = noOfHourGlass;
		}

		noOfHourGlass++;
	}
	cout << " bld" << noOfHourGlass;

	cout << "\nSum : " << maxSum<<"\n";
	cout << "Hour glass :\n" << arr[maxHourGlass] << "  " << arr[maxHourGlass +1] << "  " << arr[maxHourGlass + 2] << "\n";
	cout <<"   " <<arr[maxHourGlass + coloumns+1]<< "   ";
	cout << "\n" << arr[maxHourGlass + 2 * (coloumns)] << "  " << arr[maxHourGlass + 2 * (coloumns)+1] << "  " << arr[maxHourGlass + 2*(coloumns)+2];
}