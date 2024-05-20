#include <iostream>
#include <fstream>
using namespace std;
#include "Matrix.h"

Matrix::Matrix()
{
	n = 2;
	m = 2;
	matrix = new int[n * m];
	for (int i = 0; i < n * m; i++)
	{
		matrix[i] = 0;
	}
}

Matrix::Matrix(int strings, int columns)
{
	n = strings;
	m = columns;
	matrix = new int[n * m];
	for (int i = 0; i < n * m; i++)
	{
		matrix[i] = 0;
	}
}

Matrix::Matrix(Matrix& M)
{
	n = M.n;
	m = M.m;
	matrix = new int[n * m];
	for (int i = 0; i < n * m; i++)
	{
		matrix[i] = M.matrix[i];
	}
}

Matrix::~Matrix()
{
	delete[] matrix;
	matrix = 0;
}

const Matrix& Matrix::operator=(const Matrix& M)
{
	if (this == &M)
	{
		return *this;
	}
	n = M.n;
	m = M.m;
	delete[] matrix;
	matrix = new int[n * m];
	for (int i = 0; i < n * m; i++)
	{
		matrix[i] = M.matrix[i];
	}

	return *this;
}

const Matrix& Matrix::operator*=(const int a)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			matrix[i * m + j] *= a;
		}
	}
	return *this;	
}

istream& operator>>(istream& stream, Matrix& M)
{
	for (int i = 0; i < (M.n * M.m); i++)
	{
		stream >> M.matrix[i];
	}
	return stream;
}

ostream& operator<<(ostream& stream, const Matrix& M)
{
	for (int i = 0; i < M.n; i++)
	{
		for (int j = 0; j < M.m; j++)
		{
			stream << M.matrix[i * M.m + j] << " ";
		}
		stream << "\n";
	}
	return stream;
}


