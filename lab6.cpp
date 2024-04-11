// Вариант 12
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

class Ball
{
    double center_x;
    double center_y;
    double center_z;
    double radius;

    public:
        void In()
        {
            cout << "Введите X координату центра шара" << endl;
            cin >> center_x;
            cout << "Введите Y координату центра шара" << endl;
            cin >> center_y;
            cout << "Введите Z координату центра шара" << endl;
            cin >> center_z;
            cout << "Введите радиус шара" << endl;
            cin >> radius;
        }

        void Out()
        {
            cout << "Координата X: " << center_x << "\nКоордината Y: " << center_y << "\nКоордината Z: " << center_z << "\nРадиус шара: " << radius << endl; 
        }

        double Square()
        {
            double V;
            float t = 4.0 / 3.0;
            V =  t * M_PI * pow(radius, 3);

            return V;
        }
};

int main()
{
    Ball FirstBall;
    FirstBall.In();
    FirstBall.Out();
    double ss = FirstBall.Square();
    cout << ss << endl;

    Ball* SecondBall = new Ball;
    SecondBall -> In();
    SecondBall -> Out();
    double ss1 = SecondBall -> Square();
    cout << ss1 << endl;

    const int count = 2; 
    Ball ThirdBall[count];
    for (int i = 0; i < count; i++)
    {
        ThirdBall[i].In();
        ThirdBall[i].Out();
        double sss = ThirdBall[i].Square();
        cout << sss << endl;

    }
    return 0;
}