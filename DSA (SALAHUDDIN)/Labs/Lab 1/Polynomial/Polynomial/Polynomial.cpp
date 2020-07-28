#include"Polynomial.h"
Polynomial::Polynomial()
{
//	cout << "Default Constructor...\n";
	this->numOfTerms = 0;
	this->coefficient = 0;
	this->power = 0;
}
Polynomial::Polynomial(const Polynomial & ref)
{
//	cout << "Copy Constructor...\n";
	this->numOfTerms = ref.numOfTerms;
	this->coefficient = new double[this->numOfTerms];
	this->power = new int[this->numOfTerms];
	for (int i = 0; i < this->numOfTerms; i = i + 1)
	{
		this->coefficient[i] = ref.coefficient[i];
		this->power[i] = ref.power[i];
	}
}
Polynomial & Polynomial::operator=(const Polynomial & ref)
{
//	cout << "Assignment Operator...\n";
	if (this != (&ref))
	{
		this->~Polynomial();
		this->numOfTerms = ref.numOfTerms;
		this->coefficient = new double[this->numOfTerms];
		this->power = new int[this->numOfTerms];
		for (int i = 0; i < this->numOfTerms; i = i + 1)
		{
			this->coefficient[i] = ref.coefficient[i];
			this->power[i] = ref.power[i];
		}
	}
	return (*this);
}
Polynomial Polynomial::operator  + (const Polynomial & ref)
{
//	cout << "'+' Operator...\n";
	Polynomial sum;
	bool isPowFound = false;
	int maxPow;
	if (this->getDegree() > ref.getDegree())
		maxPow = this->getDegree();
	else
		maxPow = ref.getDegree();
	for (int power = maxPow; power >= 0; power = power - 1)
	{	
		isPowFound = false;
		if (this->isPowerAlreadyExist(power) == true && ref.isPowerAlreadyExist(power) == true)
		{
			for (int i = 0; (i < this->numOfTerms)&&(isPowFound == false); i = i + 1)
			{
				if (this->power[i] == power)
				{
					for (int j = 0; (j < ref.numOfTerms) && (isPowFound == false); j = j + 1)
					{
						if (this->power[i] == ref.power[j])
						{
							sum.addTerm((this->coefficient[i] + ref.coefficient[j]), (this->power[i]));
							isPowFound = true;
						}
					}
				}
			}
		}
		else if (this->isPowerAlreadyExist(power) == true)
		{
			for (int i = 0; (i < this->numOfTerms)&&(isPowFound==false); i = i + 1)
			{
				if (power == this->power[i])
				{
					sum.addTerm(this->coefficient[i], this->power[i]);
					isPowFound = true;
				}
			}
		}
		else if (ref.isPowerAlreadyExist(power) == true)
		{
			for (int i = 0; (i < ref.numOfTerms) && (isPowFound == false); i = i + 1)
			{
				if (power == ref.power[i])
				{
					sum.addTerm(ref.coefficient[i], ref.power[i]);
					isPowFound = true;
				}
			}
		}
	}
	return sum;
}
Polynomial Polynomial::operator  - (const Polynomial & ref)
{
//	cout << "'-' Operator...\n";
	Polynomial difference;
	bool isPowFound = false;
	int maxPow;
	if (this->getDegree() > ref.getDegree())
		maxPow = this->getDegree();
	else
		maxPow = ref.getDegree();
	for (int power = maxPow; power >= 0; power = power - 1)
	{
		isPowFound = false;
		if (this->isPowerAlreadyExist(power) == true && ref.isPowerAlreadyExist(power) == true)
		{
			for (int i = 0; (i < this->numOfTerms) && (isPowFound == false); i = i + 1)
			{
				if (this->power[i] == power)
				{
					for (int j = 0; (j < ref.numOfTerms) && (isPowFound == false); j = j + 1)
					{
						if (this->power[i] == ref.power[j])
						{
							difference.addTerm((this->coefficient[i] - ref.coefficient[j]), (this->power[i]));
							isPowFound = true;
						}
					}
				}
			}
		}
		else if (this->isPowerAlreadyExist(power) == true)
		{
			for (int i = 0; (i < this->numOfTerms) && (isPowFound == false); i = i + 1)
			{
				if (power == this->power[i])
				{
					difference.addTerm(this->coefficient[i], this->power[i]);
					isPowFound = true;
				}
			}
		}
		else if (ref.isPowerAlreadyExist(power) == true)
		{
			for (int i = 0; (i < ref.numOfTerms) && (isPowFound == false); i = i + 1)
			{
				if (power == ref.power[i])
				{
					difference.addTerm(ref.coefficient[i], ref.power[i]);
					isPowFound = true;
				}
			}
		}
	}
	return difference;
}
Polynomial Polynomial::operator  * (const Polynomial & ref)
{
//	cout << "'*' Operator...\n";
	Polynomial product;
	for (int i = 0; (i < this->numOfTerms); i = i + 1)
	{
		for (int j = 0; (j < ref.numOfTerms); j = j + 1)
			product.addTerm((this->coefficient[i] * ref.coefficient[j]), (this->power[i] + ref.power[j]));
	}	
	return product;
}
Polynomial::~Polynomial()
{
//	cout << "Destructor...\n";
	if (this->coefficient != 0 || this->power != 0)
	{
		this->numOfTerms = 0;
		delete[] this->coefficient;
		delete[] this->power;
	}
}
void Polynomial::swapTerms(int index1, int index2)
{
	if (index1 >= 0 && index1 < this->numOfTerms && index2 >= 0 && index2 < this->numOfTerms)
	{
		double cofficientTemp = this->coefficient[index1];
		int powerTemp = this->power[index1];
		this->coefficient[index1] = this->coefficient[index2];
		this->power[index1] = this->power[index2];
		this->coefficient[index2] = cofficientTemp;
		this->power[index2] = powerTemp;
	}
}
void Polynomial::sortPolynomial()
{
	for (int ind1 = 0; ind1 < this->numOfTerms; ind1 = ind1 + 1)
	{
		int highestPower = this->power[ind1];
		for (int ind2 = ind1 + 1; ind2 < this->numOfTerms; ind2 = ind2 + 1)
		{
			if (this->power[ind2] > highestPower)
			{
				this->swapTerms(ind1, ind2);
			}
		}
	}
}
void Polynomial::resizePolynomial()
{
	int * coefficientCopy = new int[this->numOfTerms];
	int * powerCopy = new int[this->numOfTerms];
	for (int i = 0; i < this->numOfTerms; i = i + 1)
	{
		coefficientCopy[i] = this->coefficient[i];
		powerCopy[i] = this->power[i];
	}
	delete[] this->coefficient;
	delete[] this->power;
	this->numOfTerms = this->numOfTerms + 1;
	this->coefficient = new double[this->numOfTerms];
	this->power = new int[this->numOfTerms];
	for (int i = 0; i < this->numOfTerms - 1; i = i + 1)
	{
		this->coefficient[i] = coefficientCopy[i];
		this->power[i] = powerCopy[i];
	}
	delete[] coefficientCopy;
	delete[] powerCopy;
}
bool Polynomial::isPowerAlreadyExist(int power)const
{
	for (int i = 0; i < this->numOfTerms; i = i + 1)
	{
		if (power == this->power[i])
			return true;
	}
	return false;
}
void Polynomial::addTerm(double coefficient, int power)
{
	if (power < 0)
		cout << "Negative Power is not allowed...\n";
	else if (this->isPowerAlreadyExist(power) == false)
	{
		this->resizePolynomial();
		this->coefficient[this->numOfTerms - 1] = coefficient;
		this->power[this->numOfTerms - 1] = power;
		this->sortPolynomial();
	}
	else {
		bool isCoefficientAdded = false;
		for (int i = 0; (i < this->numOfTerms)&&(isCoefficientAdded == false); i = i + 1)
		{
			if (power == this->power[i])
			{
				this->coefficient[i] = this->coefficient[i] + coefficient;
				isCoefficientAdded = true;
			}
		}
	}
}
void Polynomial::displayPolynomial()const
{
	cout << "*** Total Terms : " << this->numOfTerms << " ***\n\n";
	for (int i = 0; i < this->numOfTerms; i = i + 1)
	{
		cout << "Term No " << i + 1 << " :- \n"
			<< "Coefficient : " << this->coefficient[i] << "\n"
			<< "Power : " << this->power[i] << "\n\n";
	}
}
int Polynomial::getDegree()const
{
	return this->power[0];
}
double Polynomial::getCoefficient(int power)const
{
	try {
		if (this->isPowerAlreadyExist(power) == true)
		{
			bool isCoefficientFound = false;
			for (int i = 0; (i < this->numOfTerms) && (isCoefficientFound == false); i = i + 1)
			{
				if (power == this->power[i])
				{
					return this->coefficient[i];
					isCoefficientFound = true;
				}
			}
		}
		else
			throw "This Power does not exit...\n";
	}
	catch (char * message) {
		cout << message;
	}
}
int Polynomial::takePowerOfX(int value , int power)const
{
	try {
		if (power >= 0)
		{
			int ans = 1;
			for (int i = 0; i < power; i = i + 1)
				ans = ans*value;
			return ans;
		}
		else
			throw "Negative power is not allowed...\n";
	}
	catch (char * message) {
		cout << message;
	}
	
}
int Polynomial::solvePolynomialOperator(int value)const
{
	int sum = 0;
	for (int i = 0; i < this->numOfTerms; i = i + 1)
		sum = sum + (this->coefficient[i] * this->takePowerOfX(value, this->power[i]));
	return sum;
}
Polynomial Polynomial::derivative()const
{
	Polynomial derivative;
	for (int i = 0; i < this->numOfTerms; i = i + 1)
	{
		if(this->power[i] != 0)
			derivative.addTerm((this->coefficient[i] * this->power[i]), (this->power[i] - 1));
	}
	return derivative;
}
Polynomial Polynomial::antiDerivative()const
{
	Polynomial antiDerivative;
	for (int i = 0; i < this->numOfTerms; i = i + 1)
	{
		antiDerivative.addTerm((this->coefficient[i] / (this->power[i]+1)), (this->power[i] + 1));
	}
	return antiDerivative;
}
void Polynomial::addToCoefficient(double valueToBeAdded, int power)
{
	bool isPowerFound = false;
	for (int i = 0; (i < this->numOfTerms)&&(isPowerFound == false); i = i + 1)
	{
		if (this->power[i] == power)
		{
			this->coefficient[i] = this->coefficient[i] + valueToBeAdded;
			isPowerFound = true;
		}
	}
}
void Polynomial::clear()
{
	for (int i = 0; i < this->numOfTerms; i = i + 1)
		this->coefficient[i] = 0;
}
void Polynomial::setCoefficient(double newCoefficient , int power)
{
	bool isPowerFound = false;
	for (int i = 0; (i < this->numOfTerms)&&(isPowerFound == false); i = i + 1)
	{
		if (this->power[i] == power)
		{
			this->coefficient[i] = newCoefficient;
			isPowerFound = true;
		}
	}
}