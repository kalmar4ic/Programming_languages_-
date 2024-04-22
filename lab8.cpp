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

        center_x = 0 + rand() % (10 - 0 + 1);
        center_y = 0 + rand() % (10 - 0 + 1);
        center_z = 0 + rand() % (10 - 0 + 1);
        radius = 0 + rand() % (10 - 0 + 1);
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

    const Ball& operator= (const Ball& V);
    const Ball& operator*= (const float s);
    bool operator< (const float s);

    ~Ball() {}
};

const Ball& Ball::operator= (const Ball& V)
{
    if (this == &V)
    {
        return *this;
    }
    center_x = V.center_x;
    center_y = V.center_y;
    center_z = V.center_z;
    radius = V.radius;
    return *this;
}

const Ball& Ball::operator*= (const float s)
{
    //center_x *= s;
    //center_y *= s;
    //center_z *= s;
    radius *= s;
    return *this;
}

bool Ball::operator< (const float s)
{
    if (radius < s)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    // Использование конструктора по умолчанию
    Ball FirstBall;
    // FirstBall.In();
    //FirstBall.Out();
    double ss = FirstBall.Square();
    cout << ss << endl;

    //Использование конструктора с параметрами
    Ball SecondBall(4, 15, 36, 5);
    //SecondBall.Out();
    double sss = SecondBall.Square();
    cout << sss << endl;

    //Использование конструктора копирования
    Ball ThirdBall(SecondBall);
    //ThirdBall.Out();
    double sssr = ThirdBall.Square();
    cout << sssr << endl;


    Ball test1(1, 4, 6, 5), test2(5, 6, 21, 9);
    test1.Out();
    test2.Out();
    test1 = test2;
    test1.Out();
    test1 *= 5.1;
    test1.Out();
    if (test1 < 155.2)
    {
        cout << "Radius less than number" << endl;
    }
    else
    {
        cout << "Radius is greater than the number" << endl;
    }
}