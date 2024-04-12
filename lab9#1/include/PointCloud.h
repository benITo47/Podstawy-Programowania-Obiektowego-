#ifndef POINTCLOUD_H
#define POINTCLOUD_H

#include <iostream>
#include <vector>
#include <array>
#include <iomanip>

class Point2D
{
private:
    std::array<double, 2> Point;

public:
    static int DISPLAY_PRESITION;

    ///@brief konstruktor inicjalizuje obiekt zerami
    Point2D();

    ///@brief konstruktor inicializujacy obiekt przekazywana std::array
    Point2D(std::array<double, 2> initial);

    ///@brief konstruktor ustawiajacy obie wspolrzedne na przekazana wartosc
    Point2D(double x);

    Point2D(int x);

    static std::string to_string(const Point2D& refPoint);


    /// @brief Funkcja wypisuje na ekran wspolrzedne wszystkich punktow zawartych w chmurze
    void displayCoordinates() const;

    /// @brief funkcja sumuje wszystkie wspolrzedne punktu
    /// @return  zwraca sume wspolrzednych
    double PointSum();

    explicit operator double() const;
    operator std::string() const;

    friend class VPointCloud2D;
};

class VPointCloud2D
{
private:
    std::vector<Point2D *> Cloud;

public:
    VPointCloud2D();

    /// @brief konstruktor kopiujacy klasy VPointCloud2D
    VPointCloud2D(const VPointCloud2D &other);

    /// @brief konstruktor przenoszacy klasy VPointCloud2D
    VPointCloud2D(VPointCloud2D &&other) noexcept;

    ~VPointCloud2D();

    /// @brief funkcja dodaje wskaznik na punkt do chmury
    /// @param point  wskaznik na punkt
    void addPoint(Point2D *point);

    /// @brief funkcja inicjalizuje nwoy Punkt i dodaje wskaznik na ten punkt do chmury
    /// @param initialP - std::array do inicjalizacji Point2D w ciele funkcji 
    void addPoint(std::array<double, 2> initialP);

    /// @brief funkcja wyswietla zawarte w chmruze punkty i ich wspolrzedne
    void displayPoints();



    /// @brief funkcja zwraca wskaznik na Punkt ktory znajduje sie w chmruze na podanym jako parametr funkcji indeksie
    /// @param index - index punktu w chmurze
    /// @return - wskaznik na punkt
    Point2D *getCopyPoint(int index);

    /// @brief funkcja dodaje do chmury zawartosc innej chmury 
    /// @param otherCloud - przekazywana chmura
    void add(VPointCloud2D otherCloud);
    void addPoint();
    /// @brief funkcja sumuje i wypisuje ba ekran sume wszystkich wspolrzednych wszystkich punktow chmury
    void displaySumOfPoints();
};

#endif

