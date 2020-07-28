#include<iostream>
using namespace std;
#include"Stack.h"
void swapNumbers(int & firstNum, int & secondNum)
{
	int temp = firstNum;
	firstNum = secondNum;
	secondNum = temp;
}
void ascendingBubbleSorting(int * arr, int size)
{
	int swaps;
	do {
		swaps = 0;
		for (int i = 0; i < (size - 1); i = i + 1)
		{
			if (arr[i] > arr[i + 1])
			{
				swapNumbers(arr[i], arr[i + 1]);
				swaps = swaps + 1;
			}
		}
	} while (swaps != 0);
}
Stack<int> reverse(const Stack<int> &s) {
	Stack<int> oldStackCopy = s;
	Stack<int> newStack;
	int elementPoped;
	for (int i = 0; i < s.getNumOfElements(); i = i + 1) {
		elementPoped = oldStackCopy.popElement();
		newStack.pushElement(elementPoped);
	}
	return newStack;
}
Stack<int> sort(const Stack<int> &s) {
	Stack<int> oldStackCopy = s;
	int * arr = new int[oldStackCopy.getNumOfElements()];
	for (int i = 0; i < s.getNumOfElements(); i = i + 1) {
		arr[i] = oldStackCopy.popElement();
	}
	ascendingBubbleSorting(arr , s.getNumOfElements());
	Stack<int> newStack;
	for (int i = 0; i < s.getNumOfElements(); i = i + 1) {
		newStack.pushElement(arr[i]);
	}
	return newStack;
}
int findMax(const Stack<int> &s) {
	Stack<int> oldStackCopy = s;
	int * arr = new int[oldStackCopy.getNumOfElements()];
	for (int i = 0; i < s.getNumOfElements(); i = i + 1) {
		arr[i] = oldStackCopy.popElement();
	}
	ascendingBubbleSorting(arr, s.getNumOfElements());
	return arr[s.getNumOfElements() - 1];
}
int main()
{
	Stack<int> oldStack;
	oldStack.pushElement(19);
	oldStack.pushElement(18);
	oldStack.pushElement(22);
	oldStack.pushElement(20);
	oldStack.pushElement(21);
	oldStack.pushElement(25);
	oldStack.pushElement(9);
	oldStack.pushElement(8);
	oldStack.displayStack();
	cout << "\nReversed Stack : ";
	reverse(oldStack).displayStack();
	cout << "\nSorted Stack : ";
	sort(oldStack).displayStack();
	cout << "\nMaximum in Stack : ";
	cout<<findMax(oldStack);
	cout << "\n\n\n";
	return 0;
}