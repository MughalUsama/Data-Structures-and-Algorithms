#include <iostream>
#include "Polynomial.h"
using namespace std;


int main()
{
	Polynomial a, b;
	a.addTerm(3, 1);
	a.addTerm(4, 2);
	a.addTerm(5, 3);
	a.addTerm(3, 4);

	a.printPolynomial();
	cout << "\n\n";

	b.addTerm(1, 1);
	b.addTerm(1, 2);
	b.addTerm(2, 3);
	b.addTerm(3, 4);

	b.printPolynomial();
	cout << "\n\n";




	cout << "\n";
	system("pause");
	return 0;
}