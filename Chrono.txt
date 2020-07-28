#include <iostream>
#include <chrono>


using namespace std::chrono;

using namespace std;

void doSomethingWorkHorse()
{
	unsigned int sum = 0;
	for (int i = 0; i < INT_MAX; i++)
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
	high_resolution_clock::time_point t1 = high_resolution_clock::now();	
	cout << "Execution in process...\n\n\n";
	doSomething(1);
	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	cout << "Execution Stopped.\n";

	auto duration = duration_cast<microseconds>(t2 - t1).count();

	cout << "Time elapsed : ";
	cout << duration << " microseconds.";


	cout << "\n";
	system("pause");
	return 0;
}