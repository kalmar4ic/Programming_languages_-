// Лабораторная работа №2 (Вариант №6)
// Дан текстовый файл с вещественными числами. 
// Переписать все целые части исходных чисел в один файл, 
// а дробные – в другой файл.

#include <iostream>
#include <fstream>
#include <ostream>
using namespace std;

void func(fstream & fin, ofstream & fim, ofstream & fib)
{
    double chislo;
    float ost;

        while (fin >> chislo)
    {
        fim << int(chislo) << " ";
        fib << (chislo - int(chislo)) << " ";
    }
}

int main()
{
    fstream fin;
    ofstream fim;
    ofstream fib;
    fin.open("1.txt");
    fim.open("2.txt");
    fib.open("3.txt");
    if (!fin)
    {
        cout << "\n Нет исходного файла\n";
        return -1;
    }
    func(fin, fim, fib);
    cout << "Работает" << endl;
    fin.close();
    fim.close();
    fib.close();

}