#include <iostream>
#include <vector>
#include <string>
#include <core_numeric/core_numeric.h>
#include <core_numeric/custom_types.h>

int main() {

    //---Tipos fundamentales----

    //valido: int satisface Addable (operator+ definido)
    std::vector<int> a{1, 2, 3, 4};
    std::cout << core_numeric::sum(a) << "\n"; 

    //valido: double satisface Addable
    std::vector<double> b{1.5, 2.5, 3.0};
    std::cout << core_numeric::sum(b) << "\n"; 

    //no compila: const char* no satisface Addable
    //no existe operator+ entre punteros
    //std::vector<const char*> c{"hola", "hoal"};
    //core_numeric::sum(c);
    //const char* no cumple el concept Addable

    //---Objetos de clase----

    //coordenadas satisface Addable (tiene operator+ que retorna Coordenadas)
    std::vector<Coordenadas> v{{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}};
    std::cout << core_numeric::sum(v) << "\n";

    //Vector3D satisface Addable (tiene operator+ que retorna Vector3D)
    std::vector<Vector3D> w{{1.0, 0.0, 0.0}, {0.0, 2.0, 0.0}, {0.0, 0.0, 3.0}};
    std::cout << core_numeric::sum(w) << "\n";

    //no compila: std::vector<int> no satisface Addable
    //operator+ de vector no retorna vector<int>
    //std::vector<std::vector<int>> vv{{1, 2}, {3, 4}};
    //core_numeric::sum(vv);
    //std::vector<int> no cumple el concept Addable

    return 0;
}
