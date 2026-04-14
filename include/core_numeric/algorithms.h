#pragma once

#include <concepts>
#include <iterator>
#include <type_traits>

namespace core_numeric {

// sum
template <Iterable C>
requires Addable<typename C::value_type>
auto sum(const C& container) {
    using T = typename C::value_type;
    T result{};
    for (const auto& value : container) {
        result = result + value;
    }
    return result;
}

// mean
template <Iterable C>
requires Divisible<typename C::value_type>
auto mean(const C& container) {

    using T = typename C::value_type;

    auto s = sum(container);

    std::size_t count = 0;
    for (const auto& _ : container) {
        ++count;
    }

    if constexpr (std::is_integral_v<T>) {
        return static_cast<double>(s) / static_cast<double>(count);
    } else {
        return s / count;
    }
}

// variance
template <Iterable C>
requires Addable<typename C::value_type> && Multiplicable<typename C::value_type>
auto variance(const C& container) {

    using T = typename C::value_type;

    T m = static_cast<T>(mean(container));

    T result{};
    std::size_t count = 0;

    for (const auto& value : container) {
        auto diff = value - m;
        result = result + (diff * diff);
        ++count;
    }

    return result / count;
}

// max
template <Iterable C>
requires std::totally_ordered<typename C::value_type>
auto max(const C& container) {

    using T = typename C::value_type;

    auto it = std::begin(container);
    T m = *it;

    for (const auto& value : container) {
        if (value > m) {
            m = value;
        }
    }

    return m;
}

// transform_reduce
template <Iterable C, typename F>
requires Addable<typename C::value_type>
auto transform_reduce(const C& container, F f) {

    using T = typename C::value_type;

    T result{};

    for (const auto& value : container) {
        result = result + f(value);
    }

    return result;
}

} // namespace core_numeric


