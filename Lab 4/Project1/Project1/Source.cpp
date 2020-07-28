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

const char* emilysSum(const char *num1, const char*num2)
{
	Stack<int> n1;
	Stack<int> n2;
	Stack<int> sum;

	for (int i = 0; num1[i]!='\0' ; i++)
	{
		n1.push(num1[i]-'0');
	}
	for (int i = 0; num2[i] != '\0'; i++)
	{
		n2.push(num2[i]-'0');
	}
	int carry = 0;
	while (!n1.isEmpty() && !n2.isEmpty())
	{
		sum.push((n1.top() + n2.top()+carry) % 10);
		carry = (n1.top() + n2.top() + carry) / 10;
		n1.pop();
		n2.pop();
	}
	if (n1.isEmpty())
	{
		while (!n2.isEmpty())
		{
			sum.push(n2.top());
			n2.pop();
		}
	}
	else
	{
		while (!n1.isEmpty())
		{
			sum.push(n1.top());
			n1.pop();
		}
	}
	char *newSum = new char[sum.getNoOfElements()+1];
	int i = 0;
	newSum[sum.getNoOfElements()] = '\0';
	while(!sum.isEmpty())
	{
		newSum[i]=sum.top()+'0';
		sum.pop();
		i++;

	}

	return newSum;
}


int main()
{
	cout << emilysSum("1231", "00100000200");





	cout << "\n";
	return 0;
}