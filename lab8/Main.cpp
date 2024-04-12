// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal się
// a wynik jego dzialania byl taki sam jak podany na końcu tego pliku
//
// Ostateczny program powinien byc przyjazny dla programisty
// (miec czytelny i dobrze napisany kod, bez powielania kodu - D.R.Y)
//
// Celem zadania jest refaktoryzacja i rozszerzenie klas Point2D oraz VPointCloud z poprzednich zajęć.
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
    const Point2D myPoint2D_1({2.2, 1.4});
    myPoint2D_1.displayCoordinates();

    // do ustawienia precyzji można wykorzystać nagłówka <iomanip>
    // std::cout << std::fixed; oraz std::setprecision(n)
    Point2D::DISPLAY_PRESITION = 2;

    Point2D myPoint2D_2; // delegacja ctr'a
    myPoint2D_2.displayCoordinates();

    Point2D myPoint2D_3(4.0);
    myPoint2D_3.displayCoordinates();

    std::cout << "Chmura punktow 1:\n";
    VPointCloud2D myVPointCloud_1; // wersja z std::vector
    myVPointCloud_1.addPoint(new Point2D({2.0, 2.0})); // przechowujemy wskaźniki na Point2D
    myVPointCloud_1.addPoint({8.0, 7.0});
    myVPointCloud_1.displayPoints();

    std::cout << "Chmura punktow 2:\n";
    VPointCloud2D myVPointCloud_2;
    // VPointCloud::getCopyPoint(i) zwraca ptr na kopię punktu przechowywanego pod indeksem = i
	myVPointCloud_2.addPoint(myVPointCloud_1.getCopyPoint(0));
    myVPointCloud_2.displayPoints();

    std::cout << "Dodawanie punktow: \n";
    std::cout << "Chmura punktow 1 + 2:\n";
    myVPointCloud_1.add(myVPointCloud_2);
    myVPointCloud_1.displayPoints();

    std::cout << "Chmura punktow 2 + 2:\n"; // Wykonana kopia punktów.
    myVPointCloud_2.add(myVPointCloud_2);
    myVPointCloud_2.displayPoints();

    std::cout << "Przenoszenie punktow miŕdzy obiektami, 2 -> 3:\n";
    VPointCloud2D myVPointCloud_3(std::move(myVPointCloud_2));
    myVPointCloud_3.displayPoints();

    std::cout << "Sumowanie wszystkich punktow w chmurze 1:\n";


    myVPointCloud_1.displaySumOfPoints();

    return 0; //*/
}

/* wynik dzialania
Wspolrzedne: (2.2, 1.4)
Wspolrzedne: (0.00, 0.00)
Wspolrzedne: (4.00, 4.00)
Chmura punktow 1:
Wspolrzedne: (2.00, 2.00)
Wspolrzedne: (8.00, 7.00)
Chmura punktow 2:
Wspolrzedne: (2.00, 2.00)
Dodawanie punktow:
Chmura punktow 1 + 2:
Wspolrzedne: (2.00, 2.00)
Wspolrzedne: (8.00, 7.00)
Wspolrzedne: (2.00, 2.00)
Chmura punktow 2 + 2:
Wspolrzedne: (2.00, 2.00)
Wspolrzedne: (2.00, 2.00)
Przenoszenie punktow miŕdzy obiektami, 2 -> 3:
Wspolrzedne: (2.00, 2.00)
Wspolrzedne: (2.00, 2.00)
Sumowanie wszystkich punktow w chmurze 1:
Suma punktow: 23
 */
