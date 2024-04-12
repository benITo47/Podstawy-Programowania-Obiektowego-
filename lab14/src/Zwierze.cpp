#include "Zwierze.h"

void Ptak::wyswietlInformacje() const
{
    MiejsceWystepowania.wyswietlInformacje();
}
void Ptak::wydajDzwiek() const
{
    std::cout << "Ptak wydaje dźwięk!" << std::endl;
}

void Ssak::wyswietlInformacje() const 
{
    return;
}
void Ssak::wydajDzwiek() const 
{
    std::cout << "Ssak wydaje dźwięk!" << std::endl;
}

