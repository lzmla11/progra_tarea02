#include <iostream>
#include <vector>
#include <string>
#include <core_numeric/core_numeric.h>

int main() {

    std::vector<double> a{1, 2, 3, 4};

    //válido
    std::cout << core_numeric::variance(a) << "\n";

    // no compila
    // std::vector<std::string> d{"a","b"};
    // core_numeric::variance(d);
    // ERROR: no cumple Addable / Multiplicable

    return 0;
}
