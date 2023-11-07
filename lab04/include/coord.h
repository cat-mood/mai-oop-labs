#pragma once

#include <iostream>
#include <concepts>
#include <cmath>

const double EPS = 1e-7;

bool is_eq(double x, double y) noexcept {
    return std::fabs(x - y) < EPS;
}

template <class T>
requires std::is_convertible_v<T, double>
using Coord = std::pair<T, T>;

template <class T>
bool operator==(Coord<T> x, Coord<T> y) noexcept {
    return is_eq(x.first, y.first)
    && is_eq(x.second, y.second);
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Coord<T> & c) {
    os << "(" << c.first << "; " << c.second << ")";
    return os;
}

template <class T>
std::istream& operator>>(std::istream& is, Coord<T> & c) {
    is >> c.first >> c.second;
    return is;
}
