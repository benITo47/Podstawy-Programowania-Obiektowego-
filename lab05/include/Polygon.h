#pragma once
#include "Point.h"
using namespace std; 
class Polygon
{
	public: 
	string _Nazwa; 
	int _liczbaW; 
	vector<Point> _Points;

	Polygon() ;
	Polygon(string Nazwa);
	Polygon(string Nazwa, Point p1, Point p2, Point p3);
	Polygon(string Nazwa, Point p1, Point p2, Point p3, Point p4);
	Polygon(string Nazwa, int iloscW, Point tab[]);
	~Polygon();

	void Presentation();
	void SetName(string Nazwa);

	void SetVertice(int ktory, string Nazwa, double X, double Y);
	
	Point* GetVertices();
	void SetNewVertices(int ile, Point tab[]);
	
};