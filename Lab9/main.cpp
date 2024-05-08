#include <iostream>
#include <fstream>
using namespace std;
#include "/Users/kalmar4ic/Documents/Lab6/src/lib/Ball.h"

int Ball::count = 0;

int main()
{
	Ball GlobalTest;
	Ball GlobalTest2(15, 23, 34, 47);

	ofstream fib;
	fstream fin;

	fin.open("1.txt");
	fib.open("2.txt");

	if (!fin)
	{
		cout << "Файла не существует" << endl;

	} else
	{
		while (fin >> GlobalTest)
		{
			cout << "Успешный ввод из файла" << endl;
			cout << GlobalTest << endl;	
		}
		
	}

	if (!fib)
	{
		cout << "Файла не существует" << endl;

	} else
	{
		fib << GlobalTest2;
		cout << "Успешная запись в файл" << endl;
	}
	
	fin.close();
	fib.close();
}