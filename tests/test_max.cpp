#include <iostream>
#include <vector>
#include <string>
#include <core_numeric/core_numeric.h>
#include <core_numeric/custom_types.h>

int main() {

    // ---- Tipos fundamentales ----

    //int satisface totally_ordered
    std::vector<int> a{1, 5, 3};
    std::cout << core_numeric::max(a) << "\n";
    //double satisface totally_ordered
    std::vector<double> b{1.0, 2.7, 0.3};
    std::cout << core_numeric::max(b) << "\n";

    //NO compila: std::vector<int> no satisface totally_ordered
    //no existe operator< entre vectores de forma total
    //std::vector<std::vector<int>> v{{1}, {2}};
    //core_numeric::max(v);
    //std::vector<int> no cumple el concept totally_ordered

    // ---- Objetos de clase ----

    //Esfera satisface totally_ordered
    //tiene operator>, <, >=, <=, ==, != definidos, comparando por radio
    std::vector<Esfera> e{Esfera{3.0}, Esfera{7.5}, Esfera{1.2}, Esfera{5.0}};
    std::cout << core_numeric::max(e) << "\n"; 

    //no compila: Coordenadas no satisface totally_ordered
    //no tiene operadores de comparación definidos)
    //std::vector<Coordenadas> v{{1.0, 2.0}, {3.0, 4.0}};
    //core_numeric::max(v);
    //coordenadas no cumple el concept totally_ordered

    return 0;
}
