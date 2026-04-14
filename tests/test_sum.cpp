#include <iostream>
#include <vector>
#include <string>
#include <core_numeric/core_numeric.h>

int main() {

    //Casos válidos

    std::vector<int> a{1, 2, 3, 4};
    std::vector<double> b{1.5, 2.5, 3.0};

    std::cout << core_numeric::sum(a) << "\n"; // 10
    std::cout << core_numeric::sum(b) << "\n"; // 7.0

    //Casos que NO compilan

    // std::vector<const char*> c{"hola", "mundo"};
    // core_numeric::sum(c);
    // ERROR: no cumple Addable (no existe operador + válido)

    return 0;
}
