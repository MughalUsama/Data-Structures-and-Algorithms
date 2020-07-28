#include<iostream>
#include"Queue.h"
using namespace std;
bool areInputsValid(int numOfSpiders, int selectedSpiders)
{
	if (selectedSpiders >= 1 && selectedSpiders <= 316)
	{
		if (numOfSpiders >= selectedSpiders && numOfSpiders <= selectedSpiders*selectedSpiders)
			return true;
	}
	return false;
}
Queue<int> takeInput(int & selectedSpiders)
{
	int numOfSpiders;
	bool IsInputValid;
	do
	{
		cout << "Enter numbers of spiders : ";
		cin >> numOfSpiders;
		cout << "Enter numbers of spiders to select : ";
		cin >> selectedSpiders;
		IsInputValid = areInputsValid(numOfSpiders, selectedSpiders);
	} while (IsInputValid == false);
	Queue<int> spidersPower(numOfSpiders);
	int power;
	bool isPowerValid;
	for (int i = 0; i < numOfSpiders; i = i + 1)
	{
		do
		{
			isPowerValid = true;
			cout << "Enter power of spider " << i + 1 << " : ";
			cin >> power;
			if (power<1 || power>selectedSpiders)
				isPowerValid = false;
		} while (isPowerValid == false);
		spidersPower.enQueue(power);
	}
	return spidersPower;
}
void displaySelectedSpidersIndexes(Queue<int> spidersPower, int selectedSpiders)
{
	Queue<int> indexes(spidersPower.getCapacity());
	for (int i = 0; i < spidersPower.getCapacity(); i = i + 1)
		indexes.enQueue(i + 1);
	for (int i = 0; i < selectedSpiders; i = i + 1)
	{
		Queue<int> spiderPowerTemp(selectedSpiders);
		Queue<int> indexesTemp(selectedSpiders);
		int maxPowerTemp = spidersPower.deQueue(), maxPowerIndexTemp = indexes.deQueue();
		int maxPower = maxPowerTemp , maxPowerIndex = maxPowerIndexTemp;
		int j;
		for (j = 1; j < selectedSpiders; j = j + 1)
		{
			spiderPowerTemp.enQueue(maxPowerTemp);
			indexesTemp.enQueue(maxPowerIndexTemp);
			if (spidersPower.isEmpty() == true)
				j = selectedSpiders;
			else
			{
				maxPowerTemp = spidersPower.deQueue();
				maxPowerIndexTemp = indexes.deQueue();
			}
			if (maxPowerTemp > maxPower)
			{
				maxPower = maxPowerTemp;
				maxPowerIndex = maxPowerIndexTemp;
			}
		}
		if (spidersPower.isEmpty() == false  ||  j == selectedSpiders)
		{
			spiderPowerTemp.enQueue(maxPowerTemp);
			indexesTemp.enQueue(maxPowerIndexTemp);
		}
		while (indexesTemp.isEmpty() != true)
		{
			maxPowerTemp = spiderPowerTemp.deQueue();
			maxPowerIndexTemp = indexesTemp.deQueue();
			if (maxPowerIndexTemp == maxPowerIndex)
				cout <<maxPowerIndexTemp<<" ";
			else
			{
				if (maxPowerTemp > 0)
					maxPowerTemp--;
				spidersPower.enQueue(maxPowerTemp);
				indexes.enQueue(maxPowerIndexTemp);
			}
		}
	}
}
int main()
{
	int selectedSpiders;
	Queue<int> spidersPower = takeInput(selectedSpiders);
	displaySelectedSpidersIndexes(spidersPower, selectedSpiders);
	cout << "\n\n\n";
	return 0;
}