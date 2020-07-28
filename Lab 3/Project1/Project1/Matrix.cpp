#include "Matrix.h"



Matrix::Matrix()
{
	this->rows = 0;
	this->coloumns = 0;
	this->data = 0;
}


Matrix::Matrix(int noOfRows, int noOfCol)
{
	this->rows = noOfRows;
	this->coloumns = noOfCol;
	this->data = new int[this->rows*this->coloumns];
}

Matrix::~Matrix()
{
	if (this->data != 0)
	{
		this->rows = 0;
		this->coloumns = 0;
		delete[] this->data;
	}
}
