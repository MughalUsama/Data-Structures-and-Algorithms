#include "Polynomial.h"
#include <iostream>
using namespace std;


Polynomial::Polynomial()
{
	this->noOfElements = 0;
	this->power = nullptr;
	this->co_efficients = nullptr;
}


Polynomial::~Polynomial()
{
	if (this->co_efficients!=nullptr)
	{
		delete[] this->co_efficients;
	}
	if (this->power!=nullptr)
	{
		delete[] this->power;
	}
	this->noOfElements = 0;
}

Polynomial::Polynomial(const Polynomial & ref)
{


	this->noOfElements = ref.noOfElements;
		this->co_efficients = new int[ref.noOfElements];
	this->power = new int[ref.noOfElements];

	for (int i = 0; i < noOfElements; i++)
	{
		this->power[i] = ref.power[i];
		this->co_efficients[i] = ref.co_efficients[i];
	}
	this->printPolynomial();
	cout << "\n\n";
}

void Polynomial::addTerm(int coefficient, int exponent)
{
	int index = search(power, noOfElements, exponent);
	if (index == -1)
	{
		this->resize();
		this->co_efficients[noOfElements - 1] = coefficient;
		this->power[noOfElements - 1] = exponent;
		this->sortArray();
	}
	else
	{
		this->co_efficients[index] += coefficient;
	}
}


void Polynomial::resize()
{
	int *tempCo_efficients = new int[noOfElements + 1];
	int *tempPower = new int[noOfElements + 1];
	int temp_noOfElements=this->noOfElements;
	for (int i = 0; i < noOfElements; i++)
	{
		tempCo_efficients[i] = this->co_efficients[i];
		tempPower[i] = this->power[i];
	}
	this->~Polynomial();
	this->co_efficients = tempCo_efficients;
	this->power = tempPower;
	this->noOfElements =temp_noOfElements + 1;
}

void Polynomial::sortArray()
{
	for (int i = 0; i < this->noOfElements; i++)
	{
		int tempPower,tempCoefficient, largest = i;
		for (int j = i; j < this->noOfElements; j++)
		{
			if (this->power[largest] < this->power[j])
			{
				largest = j;
			}
		}
		tempPower = this->power[i];
		tempCoefficient = this->co_efficients[i];
		this->power[i] = this->power[largest];
		this->co_efficients[i] = this->co_efficients[largest];
		this->power[largest] = tempPower;
		this->co_efficients[largest] = tempCoefficient;
	}
}


int  Polynomial::search(int *arr, int size, int key)const
{

	cout << "size" << size;
	int start = 0, end = size - 1, mid;
	if (arr != nullptr)
	{
		while (start <= end)
		{
			mid = (start + end) / 2;
			if (arr[mid] == key)
			{
				return mid;
			}
			else if (key < mid)
			{
				start = mid + 1;
			}
			else
			{
				end = mid - 1;
			}
		}
	}
	if (arr==nullptr)
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i];
		}
		cout << "nullptr"<< size;
	}

	return -1;

}

int Polynomial::getDegree()
{
	if (noOfElements != 0)
	{
		return power[0];
	}
	else
	{
		return 0;
	}
}

int Polynomial::getCoefficient(int exponent)
{
	int index=search(power, noOfElements,exponent);
	if (index<0)
	{
		return 0;
	}
	else
	{
		return co_efficients[index];
	}

}

void Polynomial::printPolynomial()const
{
	cout << " P(x) = ";
	for (int i = 0; i < noOfElements ; i++)
	{
		if (co_efficients[i] > 0 && i>0)
		{
			cout << " + ";
		}
		else if (co_efficients[i] < 0)
		{
			cout << " - ";
		}
		if (co_efficients[i] > 0)
		{
			cout << this->co_efficients[i];
		}
		else
		{
			cout << -this->co_efficients[i];
		}
		cout <<"x^" << this->power[i];	
	}
}

double Polynomial::operator()(int number)
{
	double sum = 0;
	if (noOfElements!=0)
	{
		for (int i = 0; i < noOfElements; i++)
		{
			sum = sum+(co_efficients[i]*(pow(number,this->power[i])));
		}
		return sum;
	}
	else
	{
		return 0;
	}

}

Polynomial & Polynomial::operator=(const Polynomial & ref)
{
	this->~Polynomial();
	this->noOfElements = ref.noOfElements;
	this->co_efficients = new int[ref.noOfElements];
	this->power = new int[ref.noOfElements];

	for (int i = 0; i < ref.noOfElements; i++)
	{
		this->power[i] = ref.power[i];
		this->co_efficients[i] = ref.co_efficients[i];
	}
	return *this;
}

void Polynomial::clear()
{
	for (int i = 0; i < this->noOfElements; i++)
	{
		this->co_efficients[i] = 0;
	}
}

//Polynomial Polynomial::operator+(Polynomial const ref) const
//{
//	
//}