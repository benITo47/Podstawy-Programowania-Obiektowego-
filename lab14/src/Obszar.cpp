#include "Obszar.h"

void Kontynent::wyswietlInformacje() const // implicitly virtual
{
    std::cout << "Kontynent!" << std::endl;
}

void Kraj::wyswietlInformacje() const
{
    std::cout << "Kraj" << std::endl;
}