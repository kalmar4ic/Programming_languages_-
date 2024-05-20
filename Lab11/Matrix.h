#ifndef Matrix_h
#define Matrix_h
class Matrix
{
private:
	int n;
	int m;
	int* matrix;

public:
	Matrix();
	Matrix(int strings, int columns);
	Matrix(Matrix& M);
	~Matrix();

	const Matrix& operator=(const Matrix& M);
	const Matrix& operator*=(const int a);

	friend istream& operator>> (istream& stream, Matrix& M);
	friend ostream& operator<< (ostream& stream, const Matrix& M);
};
#endif

