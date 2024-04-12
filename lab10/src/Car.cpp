#include "Car.h"
#include <string>
void Car::displayInfo()
{
    std::cout << "Brand: " << (_brandName != nullptr ? _brandName : "?") << ", Year: " << (_productionYear != 0 ? std::to_string(_productionYear) : "?") << ", Mileage: " << (_mileage != 0 ? std::to_string(_mileage) : "?") << " km\n";
}
Car::Car()
{
    _productionYear = 0;
    _mileage = 0;
    _brandName = nullptr;
}
Car::Car(const char *brand, int year, int mileage)
{
    _brandName = new char[strlen(brand) + 1];
    strcpy(_brandName, brand);
    _productionYear = year;
    _mileage = mileage;
}

Car::Car(const Car &other)
{
    _brandName = new char[strlen(other._brandName) + 1];
    strcpy(_brandName, other._brandName);
    _productionYear = other._productionYear;
    _mileage = other._mileage;
}

Car& Car::operator=(const Car &other)
{
    if (this != &other)
    {
        delete[] _brandName;
        _brandName = new char[strlen(other._brandName) + 1];
        strcpy(_brandName, other._brandName);
        this->_productionYear = other._productionYear;
        this->_mileage = other._mileage;
    }
    return *this;
}

Car::Car(Car &&other)
{

    if (this != &other)
    {
        _productionYear = other._productionYear;
        _mileage = other._mileage;
        _brandName = other._brandName;

        other._brandName = nullptr;
        other._mileage = 0;
        other._productionYear = 0;
    }
}

Car& Car::operator=(Car &&other)
{
    delete[] _brandName;
    this->_productionYear = other._productionYear;
    this->_mileage = other._mileage;
    this->_brandName = other._brandName;

    other._brandName = nullptr;
    other._mileage = 0;
    other._productionYear = 0;

    return *this;
}

Car::~Car()
{
    delete[] _brandName;
}


