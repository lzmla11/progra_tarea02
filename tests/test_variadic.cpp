#include <iostream>
#include <string>
#include <core_numeric/core_numeric.h>

int main() {

    // válidos
    std::cout << core_numeric::sum_variadic(1,2,3,4) << "\n";
    std::cout << core_numeric::mean_variadic(1,2,3,4) << "\n";
    std::cout << core_numeric::max_variadic(1,5,3,2) << "\n";

    // strings
    std::cout << core_numeric::sum_variadic(std::string("a"), std::string("b")) << "\n";

    //no compila
    // core_numeric::sum_variadic("a","b");
    // ERROR: const char* no cumple Addable

    return 0;
}
