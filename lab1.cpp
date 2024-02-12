// Лабораторная №1 по ЯП (Вариант 13)
// Написать программу, формирующую массив-результат на базе исходного массива. Выделим функции:
// 1. Заполнение массива с клавиатуры.
// 2. Вывод одномерного массива.
// 3. Формирование массива-результата, состоящего из n последних элементов исходного массива.
#include <iostream>
using namespace std;

template <class Type> // вывод массива любого типа 
void Vivod(Type *mas, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "Результат второго массива = " << mas[i] << endl;
    }
}

template <class Type> // Ввод массива с любым типом данных
void Vvod(Type *mas, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Введите число: ";
        cin >> mas[i];
    }
}

template <class Type> // Второй массив получает count чисел послдних
Type Proga(Type *mas, Type *mas2, int n, int count)
{
    int j = n - count;
    for (int i = 0; i < count; i++)
    {
        Type q = mas[j];
        j++;
        mas2[i] = q;
        
    }
    return *mas2;
}


int main()
{
    int ch, ch1, ch2;
    cout << "Сколько чисел в массивке вы бы хотели? " << endl;
    cin >> ch1;
    cout << "Какой тип чисел вы хотите ввести? 1)Int, 2)Float, 3)Double " << endl;
    cin >> ch;
    cout << "Введите сколько чисел вы хотите вывести с конца" << endl;
    cin >> ch2;

    if (ch == 1)
    {
        int A[ch1];
        Vvod(A, ch1);
        int B[ch1];
        B[ch1] = Proga(A, B, ch1, ch2);
        Vivod(B, ch2);

    } else if (ch == 2)
    {
        float A[ch1];
        Vvod(A, ch1);
        float B[ch1];
        B[ch1] = Proga(A, B, ch1, ch2);
        Vivod(B, ch2);

    } else
    {
        double A[ch1];
        Vvod(A, ch1);
        double B[ch1];
        B[ch1] = Proga(A, B, ch1, ch2);
        Vivod(B, ch2);

    }

    return 0;
}