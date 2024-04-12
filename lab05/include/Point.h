#pragma once
using namespace std; 
class Point
{
public:
    double _X;
    double _Y;
    string _Nazwa;
    Point();
    Point(string Nazwa);
    Point(string Nazwa, double X, double Y);
    ~Point();
    void Presentation();
    void SetName(string Nazwa);

    void SetX(double x);

    void SetY(double y);
};