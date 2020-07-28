#include <iostream>
#include <ctime>

using namespace std;

void doSomethingWorkHorse()
{
	unsigned int sum = 0;
	for (int i = 0; i <	INT_MAX; i++)
	{
		sum = sum + i;
	}
}

void doSomething(int forTimes)
{
	for (int i = 0; i < forTimes; i++)
	{
		doSomethingWorkHorse();
	}
}




int main()
{
	cout << "Starting execution.\n\n\n";
	unsigned int T1 = time(0);
	cout << "Execution in process...\n\n\n";
	doSomething(2);
	unsigned int T2 = time(0);

	cout << "Execution Stopped.\n";

	cout << "Time elapsed : ";
	cout <<	T2-T1;	//subtracting seconds before execution from current seconds

	cout << "\n";
	//system("pause");
	return 0;
}