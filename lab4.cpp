// Лабораторная работа № 4 (Вариант 17)
// зад. 1
// Объявить поля:
// Фамилия, имя отчество
// Номер телефона
//Адрес (структура с полями название улицы, номер дома и квартиры).
// зад.2
// Вывести фамилию, имя, отчество и адрес абонента с указанным номером телефона.

#include <iostream>
#include <iomanip>
using namespace std;

struct Address
{
    char street[80];
    int house;
    int flat;
};

struct Tel
{
    char fio[80];
    double number;
    Address addr;
};

void In(Tel & t)
{
    cout << "\n Введите ФИО ";
    cin.getline(t.fio, 80);
    cout << "\n Введите номер телефона ";
    cin >> t.number;
    cout << "\n Введите улицу ";
    cin >> t.addr.street;
    cout << "\n Введите номер дома ";
    cin >> t.addr.house;
    cout << "\n Введите номер квартиры ";
    cin >> t.addr.flat;
    cin.ignore();
}

void Out(const Tel & t)
{
    cout << setw(20) << t.fio << setw(20) << t.number << setw(20) << t.addr.street << setw(20) << t.addr.house << setw(20) << t.addr.flat << endl;
}

void MasIn(Tel* mas, int count)
{
    for (int i = 0; i < count; i++)
    {
        In(mas[i]);
    }
}   

void MasOut(Tel* mas, int count)
{
    for (int i = 0; i < count; i++)
    {
        Out(mas[i]);
    }
}

int zad42(Tel* mas, int count, double nb)
{
    int i = 0;
    for (i = 0; i < count; i++)
    {
        if (mas[i].number == nb)
        {
            return i;
        }

    }
    return -1;
}


int main()
{
    int c = 0;

    cout << "Введите кол-во  массивов структур ";
    cin >> c;
    cin.ignore();

    Tel l[c];

    MasIn(l, c);
    MasOut(l,c);

    double n = 0;
    cout << "Введите введите номер телефона для поиска ";
    cin >> n;
    cin.ignore();

    int res = zad42(l, c, n);
    if (res != -1)
    {
        cout << "Существует структура\n";
        Out(l[res]);
    } else
    {
         cout << "Структуры не существует\n";
    }
}