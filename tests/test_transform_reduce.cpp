#include <iostream>
#include <vector>
#include <core_numeric/core_numeric.h>
#include <core_numeric/custom_types.h>

int main() {

    //--Tipos fundamentales----

    //int satisface Addable, lambda retorna int
    std::vector<int> v{1, 2, 3};
    auto r = core_numeric::transform_reduce(v, [](int x) {
        return x * x;
    });
    std::cout << r << "\n";

    //std::string no satisface Addable para transform_reduce
    //operator+ de string concatena, pero el lambda intenta x * x que no existe
    //std::vector<std::string> s{"a", "b"};
    //core_numeric::transform_reduce(s, [](auto x){ return x * x; });
    //std::string no cumple el concept Addable

    //---Objetos de clase----

    //valido: Coordenadas satisface Addable, lambda retorna Coordenadas
    //el lambda eleva al cuadrado componente a componente (c * c)
    std::vector<Coordenadas> vc{{1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}};
    auto rc = core_numeric::transform_reduce(vc, [](Coordenadas c) {
        return c * c;
    });
    std::cout << rc << "\n";

    //no compila: Esfera satisface Addable pero si el lambda no retorna Esfera
    //el tipo de retorno no coincide con value_type y falla el concept:
    //std::vector<Esfera> ve{Esfera{1.0}, Esfera{2.0}};
    //core_numeric::transform_reduce(ve, [](Esfera e){ return e.r; });
    //el lambda retorna double, no Esfera, rompe Addable<Esfera>

    return 0;
}
