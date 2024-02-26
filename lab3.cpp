// Лабораторная работа №3 (Вариант №10)
// Дан текстовый файл. Определить, сколько раз указанное слово повторяется в файле. 
// Заглавные и прописные буквы считать одинаковыми.

#include <iostream>
#include <fstream>
#include <ostream>
using namespace std;

int func(fstream & fin, char slovo[30])
{
    double count = 0;
    char a[30];
    while(fin >> a)
    {
        if (strcmp(slovo, a)== 0)
        {
            count += 1;
        }
    }
    return count;
}

int main()
{

    fstream fin;
    char slovo[30];
    double count = 0;
    fin.open("1.txt");
    cout << "Введите слово: " << endl;
    cin >> slovo;
    count = func(fin, slovo);
    cout << count << endl;
}
