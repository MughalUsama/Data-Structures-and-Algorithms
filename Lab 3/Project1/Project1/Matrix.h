#ifndef MATRIX_H
#define MATRIX_H
class Matrix
{
private:
	int rows;
	int coloumns;
	int * data;

public:
	Matrix();

	Matrix(int noOfRows, int noOfCol);
	~Matrix();
};

#endif