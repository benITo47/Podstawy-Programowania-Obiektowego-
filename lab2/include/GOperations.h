#include <iostream> 


int typedef rozmiarCiagu; 

 

struct ciag{
    int rozmiar; 
    float* ciag; 
};


typedef float (*operacja)(ciag,int); 

ciag InicjalizujCiagGeometryczny(int size, float iloraz); // funkcja inicjalizuje ciag geometryczny o podanym rozmiarze i ilorazie

void Wypisz(ciag exCiag, int rozmiar); // funkcja wypisuje x elementow ciagu(gdzie x = rozmiar)


float Suma(ciag exCiag, int rozmiar); //Funkcja oblicza sume x podanych elementow ciagu i zwraca 

float Iloczyn(ciag exCiag, int rozmiar); // Funkcja oblicza iloczyn x podanych elementow ciagu i zwraca go 

float Max(ciag exCiag, int rozmiar); //Funkcja znajduje element o najwiekszej wartosci 


float Wykonaj(operacja Operacja, ciag exCiag, int size); // funkcja przyjmuje inna funkcje, oraz ciag i rozmiar  po czym wykonuje ta funkcje korzystajac z podanych parametrow



