#include <iostream>
#include "Point.h"

using namespace std;

Point::Point() : _X(0.0), _Y(0.0), _Nazwa("")
{
    cout << "Wywolanie konstruktora Point..." << endl
         << endl;
}
Point::Point(string Nazwa) : _X(0.0), _Y(0.0), _Nazwa(Nazwa)
{
    cout << "Wywolanie konstruktora Point..." << endl
         << endl;
}
Point::Point(string Nazwa, double X, double Y) : _X(X), _Y(Y), _Nazwa(Nazwa)
{
    cout << "Wywolanie konstruktora Point..." << endl
         << endl;
}
Point::~Point()
{
    cout << "Wywolanie destruktora Point..." << endl
         << endl;
}
void Point::Presentation()
{
    cout << "### Prezentacja punktu ###" << endl;
    cout << "Nazwa: " << _Nazwa << endl;
    cout << "Wspolrzedna X: " << _X << endl;
    cout << "Wspolrzedna Y: " << _Y << endl
         << endl;
}
void Point::SetName(string Nazwa)
{
    _Nazwa = Nazwa;
}

void Point::SetX(double x)
{
    _X = x;
}

void Point::SetY(double y)
{
    _Y = y;
}