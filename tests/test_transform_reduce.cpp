#include <iostream>
#include <vector>
#include <core_numeric/core_numeric.h>

int main() {

    std::vector<int> v{1,2,3};

    // válido
    auto r = core_numeric::transform_reduce(v, [](int x){
        return x * x;
    });

    std::cout << r << "\n";

    //no compila
    // std::vector<std::string> s{"a","b"};
    // core_numeric::transform_reduce(s, [](auto x){ return x * x; });
    // ERROR: no cumple Addable / Multiplicable

    return 0;
}
