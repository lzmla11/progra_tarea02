#pragma once

#include <cstddef>
#include <cmath>
#include <ostream>

// Clases propias para demostrar el uso de concepts con objetos

struct Coordenadas {
    double x{}, y{};

    Coordenadas() = default;
    Coordenadas(double x_, double y_) : x(x_), y(y_) {}

    friend Coordenadas operator+(const Coordenadas& a, const Coordenadas& b) {
        return {a.x + b.x, a.y + b.y};
    }
    friend Coordenadas operator-(const Coordenadas& a, const Coordenadas& b) {
        return {a.x - b.x, a.y - b.y};
    }
    friend Coordenadas operator*(const Coordenadas& a, const Coordenadas& b) {
        return {a.x * b.x, a.y * b.y};
    }
    friend Coordenadas operator/(const Coordenadas& a, std::size_t n) {
        return {a.x / n, a.y / n};
    }

    double norm() const { return std::sqrt(x * x + y * y); } // metodo de comparacion

    friend std::ostream& operator<<(std::ostream& os, const Coordenadas& c) {
        os << "(" << c.x << ", " << c.y << ")";
        return os;
    }
};

struct Vector3D {
    double x{}, y{}, z{};

    Vector3D() = default;
    Vector3D(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}

    friend Vector3D operator+(const Vector3D& a, const Vector3D& b) {
        return {a.x + b.x, a.y + b.y, a.z + b.z};
    }
    friend Vector3D operator-(const Vector3D& a, const Vector3D& b) {
        return {a.x - b.x, a.y - b.y, a.z - b.z};
    }
    friend Vector3D operator*(const Vector3D& a, const Vector3D& b) {
        return {a.x * b.x, a.y * b.y, a.z * b.z};
    }
    friend Vector3D operator/(const Vector3D& a, std::size_t n) {
        return {a.x / n, a.y / n, a.z / n};
    }

    double norm() const { return std::sqrt(x * x + y * y + z * z); } // metodo de comparacion

    friend std::ostream& operator<<(std::ostream& os, const Vector3D& v) {
        os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return os;
    }
};

struct Esfera {
    double r{};

    Esfera() = default;
    explicit Esfera(double r_) : r(r_) {}

    friend Esfera operator+(const Esfera& a, const Esfera& b) { return Esfera(a.r + b.r); }
    friend Esfera operator-(const Esfera& a, const Esfera& b) { return Esfera(a.r - b.r); }
    friend Esfera operator*(const Esfera& a, const Esfera& b) { return Esfera(a.r * b.r); }
    friend Esfera operator/(const Esfera& a, std::size_t n)   { return Esfera(a.r / n);   }

    friend bool operator>(const Esfera& a, const Esfera& b)  { return a.r >  b.r; }
    friend bool operator<(const Esfera& a, const Esfera& b)  { return a.r <  b.r; }
    friend bool operator>=(const Esfera& a, const Esfera& b) { return a.r >= b.r; }
    friend bool operator<=(const Esfera& a, const Esfera& b) { return a.r <= b.r; }
    friend bool operator==(const Esfera& a, const Esfera& b) { return a.r == b.r; }
    friend bool operator!=(const Esfera& a, const Esfera& b) { return a.r != b.r; }

    double volumen() const { return (4.0 / 3.0) * 3.141592653589793 * r * r * r; } // metodo de comparacion
    double area()    const { return  4.0         * 3.141592653589793 * r * r;      }

    friend std::ostream& operator<<(std::ostream& os, const Esfera& e) {
        os << "Esfera(r=" << e.r << ")";
        return os;
    }
};
