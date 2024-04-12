// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku
//
// Ostateczny program powinien byc przyjazny dla programisty
// (miec czytelny i dobrze napisany kod, bez powielania kodu - D.R.Y)
//
// Celem zadania jest refaktoryzacja i rozszerzenie klas Point2D oraz VPointCloud2D z poprzednich zajęć.
// Kolejne funkcjonalności zostały opisane w ramach funkcji main()
//
// Przy wykonaniu zadania nie wolno korzystać z internetu z wyjątkiem linków podanych wyżej,
// notatek, ani żadnych innych materialow (w tym własnych wczesniej
// przygotowanych plikow oprócz CMakeLists.txt, chyba że polecenie stanowi inaczej)
//
// Kody źródłowe muszą znajdować się w katalogu do którego nikt oprócz
// właściciela nie ma praw dostępu.
// Rozwiazanie (czyli katalog z plikami i Main.cpp należy wgrać do UPEL jako archiwum tar.gz
// UWAGA:
// * pliku Main.cpp w końcowym rozwiazaniu powinien być nie zmieniony
// * archiwum tar.gz nie powinno zawierać katalogu build/
// * brak wysłanego rozwiązania (bez względu na jego ukończenie),
//   jest tożsame z brakiem obecności na zajęciach.

#include "PointCloud.h"

int main() {

  const Point2D myPoint2D_1({1.1, 2.2});
  myPoint2D_1.displayCoordinates();

  Point2D myPoint2D_2 = 1;      // konwersja
  myPoint2D_2.displayCoordinates();

  // Konwersja Point2D na double, zwracamy długość wektora wyznaczonego
  // od początku ukł. współ. do danego punktu
  //double magnitude = myPoint2D_2; // konwersja niejawna zabroniona, 
                                    // to się nie powinno kompilować!
  double magnitude = static_cast<double>(myPoint2D_2); // ale to już OK.
  std::cout << "myPoint2D_2 (magnitude): " << magnitude << std::endl;

  // Konwersja na std::string, należy tutaj również wykorzystać std::to_string()
  // Dedykowana metoda:
  std::string myPoint2D_1_str1 = Point2D::to_string(myPoint2D_1);
  std::cout << "myPoint2D_1 str1: " << myPoint2D_1_str1 << std::endl;
  // Ale możliwa jest też kowersja niejawna:
  std::string myPoint2D_1_str2 = myPoint2D_1;
  std::cout << "myPoint2D_1 str2: " << myPoint2D_1_str2 << std::endl;

  std::cout << "Chmura punktów 1:\n";
  VPointCloud2D myVPointCloud2D_1; // wersja z std::vector
  myVPointCloud2D_1.addPoint(new Point2D({2.0, 3.0})); // przechowujemy wskaźniki na Point2D
  myVPointCloud2D_1.addPoint();
  myVPointCloud2D_1.displayPoints();

  std::cout << "Chmura 1 + Chmura 1:\n"; // tak to nie pomyłka! W tym przypadku nic nie jest kopiowane!
  myVPointCloud2D_1.add(myVPointCloud2D_1);
  myVPointCloud2D_1.displayPoints();

  std::cout << "Przenoszenie punktów między obiektami, 1 -> 2:\n";
  VPointCloud2D myVPointCloud2D_2(std::move(myVPointCloud2D_1));
  std::cout << "Chmura mv:\n";
  myVPointCloud2D_2.displayPoints();
  std::cout << "Chmura 1:\n";
  myVPointCloud2D_1.displayPoints();
  std::cout << "... puste" << std::endl;

  return 0;
}

/* wynik dzialania
(1.10, 2.20)
(1.00, 1.00)
myPoint2D_2 (magnitude): 1.41
myPoint2D_1 str1: (1.100000,2.200000)
myPoint2D_1 str2: (1.100000,2.200000)
Chmura punktów 1:
(2.00, 3.00)
(0.00, 0.00)
Chmura 1 + Chmura 1:
(2.00, 3.00)
(0.00, 0.00)
Przenoszenie punktów między obiektami, 1 -> 2:
Chmura mv:
(2.00, 3.00)
(0.00, 0.00)
Chmura 1:
... puste
 */
