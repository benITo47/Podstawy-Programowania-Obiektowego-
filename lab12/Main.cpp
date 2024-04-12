// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego pliku.
//
// Zadanie opiera się o wykorzystanie kodu programu z wcześniejszych zajęć
// Klasy Line która reprezentuje linię,
// wg. matetycznego równania: y = a *x + b, oraz pozwala na wyliczania
// wartości operatorem (), i punktu przecięcia z osią odcietych (x'ów) wg równania
// x0 = - b / a;
//
// Należy uzupełnić implementację zadania o klasę LineSmartPtr, która w rzeczywistości
// może odpowiadać tzw. std::shared_ptr, ogólnie sprytny wskaźnik.
// Funkcjonalność LineSmartPtr opiera się o następujące założenia:
// Klasa LineSmartPtr przechowuje wskaźnik do klasy Line, oraz liczbę takich odniesień,
// tzn. liczbę kopii LineSmartPtr, z których każda wskazuje na ten sam obiekt Line.
// W przypadku gdy liczba takich odniesień zostaje zredukowana do 0 to LineSmartPtr
// odpowiada za zwolnienie wskazywanego zasobu klasy Line.
// Oczywiście, należałoby pamiętać o zasadzie 0/3/5,
// co jednak do poprawności tego zadania nie jest niezbędne.

// Pliku Main.cpp, nie wolno modyfikowac.

// Ostateczny program powinien byc przyjazny dla programisty (miec
// czytelny i dobrze napisany kod), oraz powinna być spełniona zasada
// D.R.Y. - Don't Repeat Yourself.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow.

// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu.
// Rozwiazanie (czyli dodane pliki i Main.cpp należy wgrać do UPEL 
// jako archiwum tar.gz
// UWAGA:
// * archiwum powinno zawierać katalog z zadaniem, np. lab12/
// * archiwum nie powinno zawierać katalogu build/

#include<iostream>
//#include "Line.h"
#include <vector>
#include <algorithm>

class Line
{
  private:
    int a;
    int b;
  public:

  Line(): a(0), b(0){}
  Line(int first, int second): a(first), b(second){}

friend std::ostream& operator<<(std::ostream& os, const Line& obiekt) {
    double x0 = static_cast<double>(-obiekt.b)/static_cast<double>(obiekt.a);
    os << " y = " << obiekt.a <<"*x + " << obiekt.b <<"\t x0 = " << x0;
    return os;
}
  friend class LineSmartPtr;
};


class LineSmartPtr
{
private:
    int* amountOfReferences;
    Line* pointer;

public:
    LineSmartPtr() : pointer(nullptr), amountOfReferences(new int(0)) {}

    LineSmartPtr(Line* linePTR) : pointer(linePTR), amountOfReferences(new int(1)) {}

    LineSmartPtr(const LineSmartPtr& other)
        : amountOfReferences(new int(*(other.amountOfReferences))), pointer(other.pointer)
    {
        (*amountOfReferences)++;
    }

    LineSmartPtr& operator=(const LineSmartPtr& other)
    {
        if (this != &other)
        {
            if (--(*amountOfReferences) == 0)
            {
                delete pointer;
                delete amountOfReferences;
            }

            amountOfReferences = other.amountOfReferences;
            (*amountOfReferences)++;
            pointer = other.pointer;
        }
        return *this;
    }

    LineSmartPtr(LineSmartPtr&& other)
        : amountOfReferences(other.amountOfReferences), pointer(other.pointer)
    {
        other.amountOfReferences = nullptr;
        other.pointer = nullptr;
    }

    LineSmartPtr& operator=(LineSmartPtr&& other)
    {
        if (this != &other)
        {
            if (--(*amountOfReferences) == 0)
            {
                delete pointer;
                delete amountOfReferences;
            }

            amountOfReferences = other.amountOfReferences;
            other.amountOfReferences = nullptr;
            pointer = other.pointer;
            other.pointer = nullptr;
        }
        return *this;
    }

    Line& operator*() const
    {
        return *pointer;
    }

    ~LineSmartPtr()
    {
        if (--(*amountOfReferences) == 0)
        {
            delete pointer;
            delete amountOfReferences;
        }
    }
};
int main (){
  auto fa = new Line(1,2);			 // y = 1*x + 2
  std::cout << *fa << std::endl; // Przeciążony opertor << dla std::ostream

  // Inicjalizacja SmartPointer
  std::cout << "line_sptr_1..." << std::endl;
  LineSmartPtr line_sptr_1(fa);
  std::cout << *line_sptr_1 << std::endl;

  // Internal scope:
  {
    // Inicjalizacja kolejnego SmartPointer
    LineSmartPtr line_sptr_2(new Line(2,1));
    std::cout << "line_sptr_2..." << std::endl;
    std::cout << *line_sptr_2 << std::endl;
    // Przypisanie wskaźnika:
    // line_sptr_1 zwalnia* zasoby wcześniej przechowywane
    // *pytanie: co znaczy zwalnia?
    line_sptr_1 = line_sptr_2;
  } // Koniec internal scope

  std::cout << "line_sptr_1..." << std::endl;
  std::cout << *line_sptr_1 << std::endl;

	return 0;
}
/* wynik dzialania programu:
y = 1* x + 2    x0 = -2
line_sptr_1...
y = 1* x + 2    x0 = -2
line_sptr_2...
y = 2* x + 1    x0 = -0.5
line_sptr_1...
y = 2* x + 1    x0 = -0.5
*/
