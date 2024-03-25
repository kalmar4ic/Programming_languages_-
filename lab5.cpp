// Вариант 9-ый
// Написать функцию удаления последнего элемента списка, если исходным данным является адрес начала списка.
// (Общее: написать функции выделения памяти, добавление элемента в конец, вывод, вывод наоборот)
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

struct Node
{
  Tel tel;
  Node* next;
  Node* pref;
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
    cout << setw(5) << t.fio << setw(20) << t.number << setw(20) << t.addr.street << setw(20) << t.addr.house << setw(20) << t.addr.flat << endl;
}


Node* first(void) //Выделение памяти под элемент списка
{
  Node* pv = new Node;
  In(pv -> tel);
  pv -> pref = 0;
  pv -> next = 0;
  return pv;
}

Node* add(Node* pend) // Добавление элемента в конец массива
{
  Node* pv = first();
  pend -> next = pv;
  pv -> pref = pend;
  return pv;
}

Node* removeLast(Node* pBegin) // удаление последнего элемента
{
  Node* pv = pBegin;
  if (pv->next == 0)
  {
    delete(pv);
    return 0;
  }
  else
  {
    for (pv = pBegin; pv->next->next != 0; pv = pv->next);
    delete pv->next;
    pv->next = 0;


    return pv;
  }
}

void print(Node* pbegin) // Вывод структуры
{
  Node* pv = pbegin;
  for (pv = pbegin ; pv != 0; pv = pv->next)
  {
    Out(pv -> tel);
  }
}

void print_back(Node* pend) // Вывод структуры наоборот
{
  Node* pv = pend;
  for (pv = pend; pv != 0 ; pv = pv->pref)
  {
    Out(pv ->tel);
  }
}

void Delete(Node* pbegin) // Удаление всех элементов структуры
{
  Node* pv = pbegin;
  for ( pv = pbegin; pv != 0; pv = pv -> next)
  {
    delete pv;
  }
  
}

int main()
{

  int count;
  cout << "Введите кол-во структуры: ";
  cin >> count;
  cin.ignore();

  Node* pbegin, * pend;
  pend = pbegin = first();
  int ch = 0;

  for (int i = 0; i < (count - 1); i++)
    {
      pend = add(pend);
    }

  while (ch != 6)
  {
    cout << "Выберите 1, чтобы вывести структуру" << endl;
    cout << "Выберите 2, чтобы добавить элемент структуры" << endl;
    cout << "Выберите 3, чтобы удалить последний элемент структуры" << endl;
    cout << "Выберите 4, чтобы вывести структуру наоборот" << endl;
    cout << "Выберите 5, чтобы удалить все элементы структуры" << endl;
    cout << "Выберите 6, чтобы выйти" << endl;
    cin >> ch;
    cin.ignore();

    switch (ch)
    {
      case 1:
        print(pbegin);
        break;
      case 2:
        if (pbegin == 0)
        {
          pend = pbegin = first();
        }
        pend = add(pend);
        print(pend);
        cout << "Успешно добавлено" << endl;
        break;
      case 3:
        pend = removeLast(pbegin);
        if (pend == 0)
        {
          pbegin = 0;
        }
        break;
      case 4:
        print_back(pend);
        break;
      case 5:
        Delete(pbegin);
        pbegin = pend = 0;
        cout << "Успешное удаление" << endl;
        break;
      default:
        cout << "Хорошего дня :)" << endl;
    }

  }
  return 0;
}