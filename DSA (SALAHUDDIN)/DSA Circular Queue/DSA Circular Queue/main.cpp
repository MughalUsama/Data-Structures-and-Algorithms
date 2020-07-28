#include<iostream>
#include"Queue.h"
#include"Queue.cpp"
using namespace std;
int main()
{
	Queue<int> q(5);
	q.enQueue(1);
	q.enQueue(2);
	q.enQueue(3);
	q.enQueue(4);
	q.enQueue(4);
	cout << '\n';
	return 0;
}