#include <iostream>
#include <vector>
#include <string>
#include <core_numeric/core_numeric.h>

int main() {

    std::vector<int> a{1, 11, 2, 9, 3, 0};
    std::vector<double> b{1.0, 2.22, 3.1, 4.1};

    // Casos que funcionan
    std::cout << core_numeric::mean(a) << "\n";
    std::cout << core_numeric::mean(b) << "\n";

    //No compila (no cumple Divisible)
    // std::vector<std::string> d{"words", "ssss"};
    // core_numeric::mean(d);

    return 0;
}
