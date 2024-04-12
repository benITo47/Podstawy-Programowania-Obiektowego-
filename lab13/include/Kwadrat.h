#ifndef KWADRAT_H
#define KWADRAT_H

#include "Ksztalt.h"

class Kwadrat: public Ksztalt
{
  private:
    int sideLength; 
  
  public: 
  
    Kwadrat(int length): sideLength(length){}

    std::string GetParameters() const override;

    double polePow() const override;

};

#endif