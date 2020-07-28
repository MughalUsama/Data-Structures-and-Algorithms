#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

class Polynomial
{
private:
	int *power;
	int *co_efficients;
	int noOfElements;
public:
	Polynomial();
	~Polynomial();
	Polynomial(const Polynomial &);
	void resize();
	void sortArray();
	void addTerm(int coefficient, int pwr);
	int search(int *arr, int size, int key)const;
	int getDegree();
	int getCoefficient(int exponent);
	void printPolynomial()const;
	double operator()(int);
	Polynomial &operator=(const Polynomial &);
	Polynomial operator+(Polynomial const s2) const;
	void clear();

};

#endif