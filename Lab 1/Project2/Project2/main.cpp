#include <iostream>
#include <fstream>

using namespace std;

void getKthElement();

int main()
{
		
	getKthElement();
	
	cout << "\n";
	system("pause");
	return 0;
}

void getKthElement()
{
	int testCases;
	fstream file("test.txt", ios::in);
	file >> testCases;
	if (testCases>0)
	{
		for (int i = 0; i < testCases; i++)
		{
			int noOfValues;
		

				file >> noOfValues;
			if (noOfValues > 0)
			{
				int *arr = new int[noOfValues];

				for (int i = 0; i < noOfValues; i++)
				{
					file >> arr[i];
				}

				int valueOfK;

				file >> valueOfK;
				if (valueOfK <= noOfValues && valueOfK>0)
				{
					for (int i = 0; i < noOfValues; i++)
					{
						int temp, smallest = i;
						for (int j = i; j < noOfValues; j++)
						{
							if (arr[smallest] > arr[j])
							{
								smallest = j;
							}
						}
						temp = arr[i];
						arr[i] = arr[smallest];
						arr[smallest] = temp;
					}
					cout << arr[valueOfK - 1] << "\n";
				}
				else
				{
					cout << "Value of K is out of range.\n";
				}
			}
			else
			{
				cout << "No of values cannot be negative.\n";
			}
		}
	}
	else
	{
		cout << "Testcases cannot be negative\n";
	}

}

