#include <iostream>
#include <iomanip>

static double wynik_iloczynu;
static double wynik_sarrusa;

struct Point {
    double x;
    double y;
};

double CrossProduct(const Point& A, const Point& B, const Point& P) {
    double vectorAB_x = B.x - A.x;
    double vectorAB_y = B.y - A.y;
    double vectorAP_x = P.x - A.x;
    double vectorAP_y = P.y - A.y;
    
	wynik_iloczynu = (vectorAB_x * vectorAP_y) - (vectorAB_y * vectorAP_x);
    return wynik_iloczynu;
}

double SarrusMatrix(const Point& A, const Point& B, const Point& P) {
    wynik_sarrusa = (A.x * B.y) + (B.x * P.y) + (P.x * A.y) - (P.x * B.y) - (B.x * A.y) - (A.x * P.y);
    return wynik_sarrusa;
}

double difference() {
	return wynik_iloczynu - wynik_sarrusa;
}

int main() {
    Point A, B, P;

    while (true) {
        std::cout << "Wprowadz wspolrzedne punktu A (x y): ";

        if (std::cin >> A.x >> A.y) {
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Bledne dane. Wprowadz ponownie." << std::endl;
            continue;
        }
        break;
    }
        
    while (true) {

        std::cout << "Wprowadz wspolrzedne punktu B (x y): ";
        if (std::cin >> B.x >> B.y) {
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Bledne dane. Wprowadz ponownie." << std::endl;
            continue;
        }
        break;
    }

    while(true) {
        
        std::cout << "Wprowadz wspolrzedne punktu P (x y): ";
        if (std::cin >> P.x >> P.y) {
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Bledne dane. Wprowadz ponownie." << std::endl;
            continue;
        }
        break;
    }
    
    double crossProduct = CrossProduct(A, B, P);
	double sarrusMatrix = SarrusMatrix(A, B, P);

	std::cout << std::fixed << std::setprecision(16) << "Wynik iloczynu wektorowego: " << wynik_iloczynu << std::endl;
	std::cout << std::fixed << std::setprecision(16) << "Wynik metoda Sarrusa: " << wynik_sarrusa << std::endl;

    if (crossProduct == 0) {
        std::cout << "Punkt P lezy na odcinku AB." << std::endl;
    }
    else if (crossProduct > 0) {
        std::cout << "Punkt P lezy po prawej stronie odcinka AB." << std::endl;
    }
    else {
        std::cout << "Punkt P lezy po lewej stronie odcinka AB." << std::endl;
    }
    
    std::cout << std::fixed << std::setprecision(16) << "Roznica wynikow: " << difference() << std::endl;

    return 0;
}