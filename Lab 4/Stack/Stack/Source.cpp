#include <iostream>
#include "myStack.h"
#include "myStack.cpp"

Stack<int> reverse(const Stack<int>& s)
{
	Stack<int> newStack;
	int * temp = new int[s.getNoOfElements()];
	newStack = s;
	for (int i = 0; i < s.getNoOfElements(); i++)
	{
		temp[i] = newStack.top();
		newStack.pop();
	}
	for (int i = 0; i < s.getNoOfElements(); i++)
	{
		newStack.push(temp[i]);
	}
	return newStack;
}

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
			int temp,smallest = i;

			for (int j = i; j < s.getNoOfElements();j++)
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
int findMax(const Stack<int>& s)
{
	Stack<int> temp = sort(s);
	return temp.top();
}

using namespace std;

int main()
{
	Stack<int> s;
	
	s.push(2);
	s.push(7);
	s.push(40);
	s.push(-10);

	cout << findMax(s);
	


	cout << "\n";
	return 0;
}