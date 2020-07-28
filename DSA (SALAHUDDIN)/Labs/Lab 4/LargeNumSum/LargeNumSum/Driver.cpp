#include<iostream>
#include"Stack.h"
using namespace std;
int calcLength(const char * str) {
	int i = 0 , length = 0; 
	while (str[i] != '\0') {
		length = length + 1;
		i = i + 1;
	}
	return length;
}

char * emilysSum(const char * num1, const char * num2) {
	int num1Length = calcLength(num1) , num2Length = calcLength(num2);
	int num1Index = num1Length - 1, num2Index = num2Length - 1;
	int carry = 0;
	Stack<char> sum;
	while (num1Index >= 0 || num2Index >= 0) {
		int number1 = num1[num1Index] - 48 , number2 = num2[num2Index] - 48;
		if (num1Index < 0)
			number1 = 0;
		if (num2Index < 0)
			number2 = 0;
		char addAns1 = number1 + number2 + carry + 48;
		char addAns2 = ((number1 + number2 + carry)%10) + 48;
		if (number1 + number2 + carry >= 10) {
			if (num1Index <= 0 && num2Index <= 0)
			{
				sum.pushElement(((number1 + number2 + carry) % 10) + 48);
				sum.pushElement(((number1 + number2 + carry) / 10) + 48);
			}
			else
				sum.pushElement(addAns2);
			carry = ((number1 + number2 + carry) / 10);
		}
		else{
			carry = 0;
			sum.pushElement(addAns1);
		}
		num1Index = num1Index - 1;
		num2Index = num2Index - 1;
	}
//	sum.displayStack();
	int totalEle = sum.getNumOfElements();
	char * numSum = new char[sum.getNumOfElements() + 1];
	for (int i = 0; i < totalEle; i = i + 1) {
		numSum[i] = sum.popElement();
	}
	numSum[totalEle] = '\0';
	return numSum;
}

int main()
{
	cout<<emilysSum("9999999", "00000000000000020000000000000");
	cout << "\n\n\n";
	return 0;
}