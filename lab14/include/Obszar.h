#ifndef OBSZAR_H
#define OBSZAR_H

#include <iostream>

class Obszar
{
public:
    Obszar(){};
    virtual void wyswietlInformacje() const = 0;
    virtual ~Obszar() {}
};

class Kontynent : public Obszar
{
public:
    Kontynent() {}
    void wyswietlInformacje() const override; // implicitly virtual
    virtual ~Kontynent() {}
};
class Kraj final : public Kontynent
{
public:
    void wyswietlInformacje() const override;

    ~Kraj(){};
};

#endif