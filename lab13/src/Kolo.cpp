#include "Kolo.h"

std::string Kolo::GetParameters() const
{
    std::string printNote = "Kolo o promieniu: ";
    printNote += std::to_string(radius);
    return printNote;
}

double Kolo::polePow() const
{
    return (radius * radius * 3.1415);
}
