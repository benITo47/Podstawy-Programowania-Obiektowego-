#include "Kwadrat.h"

std::string Kwadrat::GetParameters() const 
{
    std::string printNote = "Kwadrat o boku: ";
    printNote += std::to_string(sideLength);
    return printNote;
}

double Kwadrat::polePow() const 
{
    return (sideLength * sideLength);
}