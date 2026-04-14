#pragma once
 
#include <concepts>
#include <type_traits>
 
namespace core_numeric {
 
// sum_variadic
template <typename T, typename... Args>
requires Addable<T>
auto sum_variadic(T first, Args... args) {
    return (first + ... + args);
}
 
// mean_variadic
template <typename T, typename... Args>
requires Addable<T> && Divisible<T>
auto mean_variadic(T first, Args... args) {
 
    auto s = sum_variadic(first, args...);
    auto count = sizeof...(args) + 1;
 
    if constexpr (std::is_integral_v<T>) {
        return static_cast<double>(s) / static_cast<double>(count);
    } else {
        return s / count;
    }
}
 
// variance_variadic
template <typename T, typename... Args>
requires Addable<T> && Divisible<T> && Multiplicable<T>
auto variance_variadic(T first, Args... args) {
 
    auto m = mean_variadic(first, args...);
 
    auto sq = [&](auto x) { return (x - m) * (x - m); };
    auto sum_sq = (sq(first) + ... + sq(args));
    auto count = sizeof...(args) + 1;
 
    return sum_sq / count;
}
 
// max_variadic
template <typename T, typename... Args>
requires std::totally_ordered<T>
auto max_variadic(T first, Args... args) {
 
    T m = first;
 
    ((m = (args > m ? args : m)), ...);
 
    return m;
}
 
} // namespace core_numeric
