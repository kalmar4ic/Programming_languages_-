// Вариант 12
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

class Ball
{
    double center_x;
    double center_y;
    double center_z;
    double radius;

public:

    Ball()
    {
        srand(time(0));

        center_x = 1 + rand() % (10 - 1 + 1);
        center_y = 1 + rand() % (10 - 1 + 1);
        center_z = 1 + rand() % (10 - 1 + 1);
        radius = 1 + rand() % (10 - 1 + 1);
    }

    Ball(double c_x, double c_y, double c_z, double r)
    {
        center_x = c_x;
        center_y = c_y;
        center_z = c_z;
        radius = r;
    }

    Ball(const Ball& V)
    {
        center_x = V.center_x;
        center_y = V.center_y;
        center_z = V.center_z;
        radius = V.radius;
    }

    void In()
    {
        cout << "Enter the X coordinate of the ball's center" << endl;
        cin >> center_x;
        cout << "Enter the Y coordinate of the ball's center" << endl;
        cin >> center_y;
        cout << "Enter the Z coordinate of the ball's center" << endl;
        cin >> center_z;
        cout << "Enter the radius of the ball" << endl;
        cin >> radius;
    }

    void Out()
    {
        cout << "X coordinate: " << center_x << "\nY coordinate: " << center_y << "\nZ coordinate: " << center_z << "\nThe radius of the ball: " << radius << endl;
    }

    double Square()
    {
        double V;
        V = (4.0 / 3.0) *M_PI * pow(radius, 3);

        return V;
    }

    ~Ball() {}
};

int main()
{
    // Использование конструктора по умолчанию
    Ball FirstBall;
    // FirstBall.In();
    FirstBall.Out();
    double ss = FirstBall.Square();
    cout << ss << endl;

    //Использование конструктора с параметрами
    Ball SecondBall(4, 15, 36, 5);
    SecondBall.Out();
    double sss = SecondBall.Square();
    cout << sss << endl;

    //Использование конструктора копирования
    Ball ThirdBall(SecondBall);
    ThirdBall.Out();
    double ssss = ThirdBall.Square();
    cout << ssss << endl;
}