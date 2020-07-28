#ifndef POLYNOMIAL_H
#define POLTNOMIAL_H
#include<iostream>
using namespace std;
class Polynomial
{
	private:
		int numOfTerms;
		double * coefficient;
		int * power;
		void resizePolynomial();
		void sortPolynomial();
		void swapTerms(int term1Index, int term2Index);
		bool isPowerAlreadyExist(int power)const;
		int takePowerOfX(int value , int power)const;
	public:
		Polynomial();
		Polynomial(const Polynomial & ref);
		Polynomial & operator = (const Polynomial & ref);
		Polynomial operator + (const Polynomial & ref);
		Polynomial operator - (const Polynomial & ref);
		Polynomial operator * (const Polynomial & ref);
		~Polynomial();
		void addTerm(double coefficient, int power);
		void displayPolynomial()const;
		int getDegree()const;
		double getCoefficient(int power)const;
		int solvePolynomialOperator(int value)const;
		Polynomial derivative()const;
		Polynomial antiDerivative()const;
		void addToCoefficient(double valueToBeAdded, int power);
		void clear();
		void setCoefficient(double newCoefficient , int power);
};

#endif