#ifndef CAR_H
#define CAR_H

#include <iostream>
class Car
{
private:
    int _productionYear;
    int _mileage;
    char *_brandName;

public:
    void displayInfo();
    Car();
    Car(const char *brand, int year, int mileage);

    Car(const Car &other);

    Car &operator=(const Car &other);

    Car(Car &&other);

    Car &operator=(Car &&other);

    ~Car();
};

#endif