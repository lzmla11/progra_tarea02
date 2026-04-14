cmake_minimum_required(VERSION 3.16)

project(progra_tarea02)

# C++20 obligatorio
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ========================
# Librería header-only
# ========================
add_library(core_numeric INTERFACE)

target_include_directories(core_numeric INTERFACE
    ${CMAKE_SOURCE_DIR}/include
)

# ========================
# Tests
# ========================

add_executable(test_sum tests/test_sum.cpp)
target_link_libraries(test_sum core_numeric)

add_executable(test_mean tests/test_mean.cpp)
target_link_libraries(test_mean core_numeric)

add_executable(test_variance tests/test_variance.cpp)
target_link_libraries(test_variance core_numeric)

add_executable(test_max tests/test_max.cpp)
target_link_libraries(test_max core_numeric)

add_executable(test_transform_reduce tests/test_transform_reduce.cpp)
target_link_libraries(test_transform_reduce core_numeric)

add_executable(test_variadic tests/test_variadic.cpp)
target_link_libraries(test_variadic core_numeric)
