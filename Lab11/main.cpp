#include <iostream>
using namespace std;
#include "/Users/kalmar4ic/Documents/Lab6/src/lib/Matrix.h"

int main()
{
	Matrix Test1;
	cin >> Test1;
	cout << endl;
	cout << Test1;

	cout << "-----------" << endl;

	Matrix Test2(3, 2);
	cin >> Test2;
	cout << endl;
	cout << Test2;

	cout << "-----------" << endl;

	Matrix Test3(Test1);
	cout << Test3;

	cout << "-----------" << endl;

	Matrix Test4;
	Test4 = Test2;
	cout << Test4;

	cout << "-----------" << endl;

	Matrix Test5;
	Test5 = Test2;
	Test5 *= 2;
	cout << Test5 << endl;
}