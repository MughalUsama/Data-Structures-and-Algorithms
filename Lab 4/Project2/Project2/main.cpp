#include <iostream>
#include "myStack.h"
#include "myStack.cpp"

Stack<int> sort(const Stack<int>& s)
{
	Stack<int> newStack;
	int * tempData = new int[s.getNoOfElements()];
	newStack = s;
	for (int i = 0; i < s.getNoOfElements(); i++)
	{
		tempData[i] = newStack.top();
		newStack.pop();
	}


	for (int i = 0; i < s.getNoOfElements(); i++)
	{
		for (int i = 0; i < s.getNoOfElements(); i++)
		{
			int temp, smallest = i;

			for (int j = i; j < s.getNoOfElements(); j++)
			{

				if (tempData[smallest] > tempData[j])
				{
					smallest = j;
				}
			}

			temp = tempData[i];

			tempData[i] = tempData[smallest];
			tempData[smallest] = temp;
		}
	}

	for (int i = 0; i < s.getNoOfElements(); i++)
	{
		newStack.push(tempData[i]);
	}
	return newStack;
}

int getPermutation()
{
	Stack<int>s;
	int noOfElements,num;
	cin >> noOfElements;

	for (int i = 0; i < noOfElements; i++)
	{
		cin >> num;
		s.push(num);
	}
	s=sort(s);
	int pairs = noOfElements-1;
	for (int i = 0; i < noOfElements-1; i++)
	{
		num = s.top();
		s.pop();
		if (num==s.top())
		{
			pairs--;
		}
	}
	return pairs;
}

int main()
{

	char n1[7] = "123000";
	char n2[5] = "";


	cout << getPermutation();



	system("pause");
	cout << "\n";
	return 0;
}