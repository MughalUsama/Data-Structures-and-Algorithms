#include<iostream>
#include"SLinkList.h"
#include"SLinkList.cpp"
#include<chrono>
using namespace std;
using namespace chrono;
int main()
{
	SLinkList<int> l;
	l.addElement(10);
	l.addElement(9);
	l.addElement(8);
	l.addElement(7);
	l.addElement(6);
	l.addElement(5);
	l.addElement(4);
	l.addElement(3);
	l.addElement(2);
	l.addElement(1);
	auto t = high_resolution_clock::now();
	l.reverse();
	cout << duration_cast<nanoseconds>(high_resolution_clock::now() - t).count() << '\n';
	l.display();
	cout << '\n';
	return 0;
}