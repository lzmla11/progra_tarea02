#include <iostream>
#include <vector>
#include <string>
#include <core_numeric/core_numeric.h>
#include <core_numeric/custom_types.h>

int main() {

    // ---- Tipos fundamentales ----

    //válido: int satisface Divisible (operator/ con size_t existe)
    //if constexpr detecta que es integral y convierte a double
    std::vector<int> a{1, 11, 2, 9, 3, 0};
    std::cout << core_numeric::mean(a) << "\n"; // 4.33333

    // Válido: double satisface Divisible
    std::vector<double> b{1.0, 2.22, 3.1, 4.1};
    std::cout << core_numeric::mean(b) << "\n"; // 2.605

    //no compila: std::string no satisface Divisible
    //(no existe operator/ entre string y size_t)
    //std::vector<std::string> d{"wwww", "ssss"};
    //core_numeric::mean(d);
    //std::string no cumple el concept Divisible

    // ---- Objetos de clase ----

    //coordenadas satisface Divisible (tiene operator/ con size_t)
    //if constexpr detecta queno es integral, usa s / count directamente
    std::vector<Coordenadas> v{{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}};
    std::cout << core_numeric::mean(v) << "\n"; // (3, 4)

    //no compila: Esfera sin operator/ no satisfaría Divisible.
    //Con un tipo que no tiene operator/ con size_t:
    //std::vector<std::vector<int>> vv{{1, 2}, {3, 4}};
    //core_numeric::mean(vv);
    //std::vector<int> no cumple el concept Divisible

    return 0;
}
