// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.

// Prosze zaimplementowac klasę Line która reprezentuje linię,
// wg. matetycznego równania: y = a *x + b, oraz pozwala na wyliczania
// wartości operatorem (), i punktu przecięcia z osią odcietych (x'ów) wg równania
// x0 = - b / a;
// Proszę zaimplementować również klasę LPrint oraz LArray które, odpowiednio
// pozwalają drukować na ekran instancję klasy Line oraz przechowywać jako tablicę
// instancje klasy Line; Uwaga: tablica LArray powinna być dynamicznie alokowana,
// z wykorzystaniem argumentu konstruktora odpowiadającemy za rozmiar tablicy.

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
// * archiwum powinno zawierać katalog z zadaniem, np. lab10/
// * archiwum nie powinno zawierać katalogu build/

//#include "Line.h"
#include<iostream>
#include <vector>
#include <algorithm>

class Line
{

    
  public:

  double ab;
  Line(double ab_val) : ab(ab_val) {}
  Line():ab(1){}
  Line(const Line& other)
  {
    this->ab =other.ab;
  }
  double operator()(double x) const {
        return ab * x + ab;
    }
  double X0() const
  {
    if(ab != 0)
    {
      return -ab/ab; 
    }
    else
    {
       return 0;
    }
  }

  friend class LPrint;
};


class LArray
{
  private:
    int size;
    Line* array;
    int currentIndex;
  public:
  LArray(int n): size(n), currentIndex(0)
  {
    array = new Line[n];
  }
  LArray(const LArray& other)
  {
    size = other.size;
    currentIndex = other.currentIndex;
    array = new Line[size];
    for(int i = 0; i<currentIndex; i++)
    {
      array[i] = other.array[i];
    }
  }
  ~LArray()
  {
    delete [] array;
  }
   void checkSize()
    {
        if (currentIndex == size)
        {
            Line* tmp = new Line[size + 1];
            for (int i = 0; i < size; i++)
            {
                tmp[i] = array[i];
            }
            delete[] array;
            array = tmp;
            size += 1;
        }
    }
  LArray& Add(Line slope)
  {
    checkSize();
    array[currentIndex] = slope;
    currentIndex++;
    return *this;
  }
  LArray& Add(double val)
  {
    
    checkSize();

    array[currentIndex] = Line(val);
    currentIndex++;
    return *this;
  }
  LArray& operator=(const LArray& other)
    {
        if (this != &other) 
        {
            delete[] array;
            size = other.size;
            currentIndex = other.currentIndex;

            array = new Line[size];
            for (int i = 0; i < currentIndex; i++)
            {
                array[i] = other.array[i];
            }
        }

        return *this;
    }
  friend class LPrint;
};
class LPrint
{
  public:
  void operator()(Line slope)
  {
    std::cout<<"y = " << slope.ab << "* x + " << slope.ab << "\tx0 = " << slope.X0() << std::endl;
  }
  void operator()(LArray arr)
  {
    for(int i = 0; i< arr.size; i++)
    {
       std::cout<<"["<< i  <<"] y = " << arr.array[i].ab << "* x + " << arr.array[i].ab << "\tx0 = " << arr.array[i].X0() << std::endl;
    }
  }
};

int main ()
{
  Line fa;			          // y = 1*x + 1
	double y1 = fa(20.0);		// y1 = 20 + 1
	std::cout << "y1 = " << y1 << "\tx0 = "<< fa.X0() << std::endl;

  LPrint print_line;
  print_line(fa);

  std::vector<Line> lines = { fa, 2, 3 };
  std::for_each(lines.begin(), lines.end(), print_line); 

  LArray arr(3);
  arr.Add(lines[1]);
  arr.Add(3).Add(4);
  print_line(arr);

	return 0;
  
}
/* wynik dzialania programu:
y1 = 21 x0 = -1
y = 1* x + 1    x0 = -1
y = 1* x + 1    x0 = -1
y = 2* x + 2    x0 = -1
y = 3* x + 3    x0 = -1
[0] y = 2* x + 2        x0 = -1
[1] y = 3* x + 3        x0 = -1
[2] y = 4* x + 4        x0 = -1
*/
