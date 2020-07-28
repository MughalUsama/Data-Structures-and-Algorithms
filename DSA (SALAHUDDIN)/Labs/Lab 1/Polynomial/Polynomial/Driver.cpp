#include<iostream>
using namespace std;
#include"Polynomial.h"
int main()
{
	Polynomial obj;
	obj.addTerm(20,4);
	obj.addTerm(21, 2);
	obj.addTerm(-2,1);
	obj.displayPolynomial();
	obj.setCoefficient(18.5, 4);
	obj.addToCoefficient(3.8, 2);
	obj.displayPolynomial();
	cout << "\n\n\n";
	return 0;
}