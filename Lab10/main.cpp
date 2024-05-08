#include <iostream>
#include <fstream>
using namespace std;
#include "/Users/kalmar4ic/Documents/Lab6/src/lib/Ball.h"

int Ball::count = 0;

int main()
{
	const int cont = 5;
	Ball* mas[cont];

	cout << "How many " << Ball::GetCount() << endl;
	for (int i = 0; i < cont; i++)
	{
		mas[i] = new Ball(25 + 1, 36 + i * 2, 3 - i, 15 + i * 6);
		cout << "How many " << Ball::GetCount() << endl;
	}

	for (int i = 0; i < cont; i++)
	{
		delete mas[i];
		cout << "How many " << Ball::GetCount() << endl;
	}

	cout << "How many " << Ball::GetCount() << endl;

	cout << "Статическое задание объекта" << endl << endl;

	cout << "How many " << Ball::GetCount() << endl;
	
	{
		Ball T1;
		cout << "How many " << Ball::GetCount() << endl;
		{
			Ball T2;
			cout << "How many " << Ball::GetCount() << endl;
			{
				Ball T3;
				cout << "How many " << Ball::GetCount() << endl;
			}
			cout << "How many " << Ball::GetCount() << endl;
		}
		cout << "How many " << Ball::GetCount() << endl;
	}
	cout << "How many " << Ball::GetCount() << endl;

	return 0;
}