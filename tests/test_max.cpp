#include <iostream>
#include <vector>
#include <string>
#include <core_numeric/core_numeric.h>

int main() {

    std::vector<int> a{1,5,3};

    //  válido
    std::cout << core_numeric::max(a) << "\n";

    //  no compila
    // std::vector<std::vector<int>> v{{1},{2}};
    // core_numeric::max(v);
    // ERROR: no cumple totally_ordered

    return 0;
}
