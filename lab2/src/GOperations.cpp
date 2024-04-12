#include<iostream>
#include"GOperations.h"
#include"GSeries.h"
using namespace std; 



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

void Wypisz(ciag exCiag, int rozmiar){

    for(int i =0; i < rozmiar; i++){
        cout << exCiag.ciag[i]<< " "; 
    }
    cout << endl; 
}

float Suma(ciag exCiag, int rozmiar){
    float suma = 0; 
    for(int i= 0; i< rozmiar; i++){
        suma += exCiag.ciag[i];
    }
    return suma;
}

float Iloczyn(ciag exCiag, int rozmiar){
    float iloczyn = exCiag.ciag[0]; 

    for(int i = 1; i< rozmiar; i++){
        iloczyn = iloczyn * exCiag.ciag[i];
    }
    return iloczyn; 
}


float Max(ciag exCiag, int rozmiar){
    float Max = exCiag.ciag[0];

    for(int i=1; i<rozmiar; i++){
        if (exCiag.ciag[i] > Max){
            Max = exCiag.ciag[i];
        }
    }

    return Max;
}


float Wykonaj(operacja Operacja, ciag exCiag, int size){
     return Operacja(exCiag, size);
}



