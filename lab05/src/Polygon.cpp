#include <iostream>
#include "Point.h"
#include "Polygon.h"

using namespace std;

Polygon::Polygon() : _liczbaW(0), _Nazwa(""), _Points(0)
{
    cout << "Wywolanie konstruktora Polygon..." << endl
         << endl;
}
Polygon::Polygon(string Nazwa) : _liczbaW(0), _Nazwa(Nazwa), _Points(0)
{
    cout << "Wywolanie konstruktora Polygon..." << endl
         << endl;
}
Polygon::Polygon(string Nazwa, Point p1, Point p2, Point p3) : _liczbaW(3), _Nazwa(Nazwa)
{
    cout << "Wywolanie konstruktora Polygon..." << endl
         << endl;
    _Points.push_back(p1);
    _Points.push_back(p2);
    _Points.push_back(p3);
}
Polygon::Polygon(string Nazwa, Point p1, Point p2, Point p3, Point p4) : _liczbaW(4), _Nazwa(Nazwa)
{
    cout << "Wywolanie konstruktora Polygon..." << endl
         << endl;
    _Points.push_back(p1);
    _Points.push_back(p2);
    _Points.push_back(p3);
    _Points.push_back(p4);
}
Polygon::Polygon(string Nazwa, int iloscW, Point tab[]) : _liczbaW(iloscW), _Nazwa(Nazwa)
{
    cout << "Wywolanie konstruktora Polygon..." << endl
         << endl;

    for (int i = 0; i < iloscW; i++)
    {
        _Points.push_back(tab[i]);
    }
}
Polygon::~Polygon()
{
    cout << "Wywolanie destruktora Polygon..." << endl
         << endl;
}

void Polygon::Presentation()
{
    cout << "### Prezentacja wielokata ###" << endl
         << endl;
    cout << "Nazwa: " << _Nazwa << endl;
    cout << "Liczba wierzcholkow: " << _liczbaW << endl;
    for (int i = 0; i < _liczbaW; i++)
    {
        cout << "Wierzcholek - nazwa: " << _Points[i]._Nazwa << " X = " << _Points[i]._X << ", Y = " << _Points[i]._Y << endl;
    }
    cout << endl;
}
void Polygon::SetName(string Nazwa)
{
    _Nazwa = Nazwa;
}

void Polygon::SetVertice(int ktory, string Nazwa, double X, double Y)
{
    _Points[ktory - 1].SetName(Nazwa);
    _Points[ktory - 1].SetX(X);
    _Points[ktory - 1].SetY(Y);
}

Point* Polygon::GetVertices()
{
    Point *tab = new Point[_liczbaW];
    for (int i = 0; i < _liczbaW; i++)
    {
        tab[i] = _Points[i];
    }
    return tab;
}
void Polygon::SetNewVertices(int ile, Point tab[])
{
    _liczbaW = ile;
    for (int i = 0; i < ile; i++)
    {
        _Points.push_back(tab[i]);
    }
}
