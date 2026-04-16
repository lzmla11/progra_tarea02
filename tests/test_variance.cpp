#include <iostream>
#include <string>
#include <core_numeric/core_numeric.h>
#include <core_numeric/custom_types.h>

int main() {

    //--- Tipos fundamentales---

    //int satisface Addable, Divisible y totally_ordered
    std::cout << core_numeric::sum_variadic(1, 2, 3, 4)  << "\n"; // 10
    std::cout << core_numeric::mean_variadic(1, 2, 3, 4) << "\n"; // 2.5
    std::cout << core_numeric::max_variadic(1, 5, 3, 2)  << "\n"; // 5

    //std::string satisface Addable (operator+ concatena)
    std::cout << core_numeric::sum_variadic(
        std::string("Hola"), std::string(" "), std::string("Mundo")
    ) << "\n";

    //no compila: const char* no satisface Addable
    //operator+ no está definido para punteros a char
    //core_numeric::sum_variadic("a", "b");
    //const char no cumple el concept Addable

    //--- Objetos de clase----

    //coordenadas satisface Addable (tiene operator+)
    std::cout << core_numeric::sum_variadic(
        Coordenadas{1.0, 0.0}, Coordenadas{2.0, 3.0}, Coordenadas{0.5, 0.5}
    ) << "\n"; 

    //Esfera satisface totally_ordered (tiene >, <, >=, <=, ==, !=)
    std::cout << core_numeric::max_variadic(
        Esfera{3.0}, Esfera{7.5}, Esfera{1.2}
    ) << "\n"; 

    //no compila: Coordenadas no satisface totally_ordered
    //no tiene operadores de comparación definidos
    //core_numeric::max_variadic(Coordenadas{1.0, 2.0}, Coordenadas{3.0, 4.0});
    //Coordenadas no cumple el concept totally_ordered

    //no compila: Esfera no satisface Divisible (no tiene operator/ con size_t)
    //core_numeric::mean_variadic(Esfera{1.0}, Esfera{2.0}, Esfera{3.0});
    //Esfera no cumple el concept Divisible

    return 0;
}
