#pragma once
 
#include <concepts>
#include <iterator>
 
namespace core_numeric {
 
template <typename C>
concept Iterable = requires(C c) {
    std::begin(c);
    std::end(c);
};
 
template <typename T>
concept Addable = requires(T a, T b) {
    { a + b } -> std::same_as<T>;
};
 
template <typename T>
concept Divisible = requires(T a, std::size_t n) {
    a / n;
};
 
template <typename T>
concept Multiplicable = requires(T a, T b) {
    { a * b } -> std::same_as<T>;
};
 
}
