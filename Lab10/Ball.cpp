#define _USE_MATH_DEFINES
#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <time.h>
using namespace std;
#include "Ball.h"

Ball::Ball()
{
	srand(time(0));

    center_x = 0 + rand() % (10 - 0 + 1);
    center_y = 0 + rand() % (10 - 0 + 1);
    center_z = 0 + rand() % (10 - 0 + 1);
    radius = 0 + rand() % (10 - 0 + 1);
    count++;
}

Ball::Ball(double c_x, double c_y, double c_z, double r)
{
    center_x = c_x;
    center_y = c_y;
    center_z = c_z;
    radius = r;
    count++;
}

Ball::Ball(const Ball& V)
{
    center_x = V.center_x;
    center_y = V.center_y;
    center_z = V.center_z;
    radius = V.radius;
    count++;
}

void Ball:: Out()
{
    cout << "X coordinate: " << center_x << "\nY coordinate: " << center_y << "\nZ coordinate: " << center_z << "\nThe radius of the ball: " << radius << endl;
}

double Ball::Square()
{
    double Volume;
    Volume = (4.0 / 3.0) * M_PI * pow(radius, 3);
    return Volume;
}

const Ball& Ball:: operator= (const Ball& V)
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

const Ball& Ball:: operator*= (const float s)
{
    radius *= s;

    return *this;
}

bool Ball:: operator< (const float s)
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

istream& operator>> (istream& stream, Ball& B)
{
    stream >> B.center_x >> B.center_y >> B.center_z >> B.radius;
    return stream;
}

ostream& operator<< (ostream& stream, const Ball& B)
{
    stream << B.center_x << " " << B.center_y << " " << B.center_z << " " << B.radius << endl;
    return stream;
}

int Ball::GetCount()
{
    return count;
}
