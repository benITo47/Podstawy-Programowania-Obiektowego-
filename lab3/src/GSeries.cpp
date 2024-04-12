#include "GSeries.h"
#include <iostream>




void UsunCiagi(){
    return;
}

ciag InicjalizujCiagGeometryczny(int size, float iloraz){
    ciag* nowyCiag = new ciag; 
    nowyCiag->rozmiar = size; 
    nowyCiag->ciag = new float[size];
    nowyCiag->ciag[0] = 1; 

    for(int i =1; i< size; i++){
        nowyCiag->ciag[i] = nowyCiag->ciag[i-1] * iloraz; 
    }
    return *nowyCiag; 
} 