#ifndef KSZTALT_H
#define KSZTALT_H 

#include <string>
#include <iostream>

class Ksztalt
{
    public: 

    virtual std::string GetParameters()const  = 0;

    virtual double polePow() const = 0;

};

void wypisz(const Ksztalt& object);

#endif 