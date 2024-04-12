#pragma once 

#ifdef PERFORME_LONG_LOOP
    #define LONG_LOOP 1
#else
    #define LONG_LOOP 0
#endif



int typedef rozmiarCiagu; 

 

struct ciag{
    int rozmiar; 
    float* ciag; 
};


typedef float (*operacja)(ciag,int); 

void UsunCiagi();

ciag InicjalizujCiagGeometryczny(int size, float iloraz);