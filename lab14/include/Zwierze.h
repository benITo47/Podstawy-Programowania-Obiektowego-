#ifndef ZWIERZE_H
#define ZWIERZE_H

#include<iostream>
#include "Obszar.h"




class Zwierze
{
  public: 
  Zwierze(){}
  virtual void wyswietlInformacje() const  = 0; 
  virtual void wydajDzwiek() const = 0;
  virtual ~Zwierze(){};
};


class Ptak final : public Zwierze
{
  private: 
    Kraj MiejsceWystepowania;
    
  public: 
    Ptak(Kraj* kraj):MiejsceWystepowania(*kraj){}
    void wyswietlInformacje() const override;
    void wydajDzwiek()const override;
    ~Ptak(){};
};

class Ssak final : public Zwierze
{
   
  public: 
    Ssak(){};
    void wyswietlInformacje() const override;
    void wydajDzwiek() const override;
    ~Ssak(){};

};

#endif