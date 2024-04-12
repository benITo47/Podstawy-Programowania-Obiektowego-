#ifndef KOLO_H
#define KOLO_H

#include <Ksztalt.h>

class Kolo : public Ksztalt
{
private:
    int radius;

public:
    Kolo(int r) : radius(r) {}

    std::string GetParameters() const override;

    double polePow() const override;
};

#endif