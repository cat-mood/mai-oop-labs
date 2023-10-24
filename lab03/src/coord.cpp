#include "coord.h"
#include <cmath>

const double EPS = 1e-7;

bool operator==(Coord x, Coord y) noexcept {
    return (std::fabs(x.first - y.first) < EPS) 
    && (std::fabs(x.second - y.second) < EPS);
}

std::ostream& operator<<(std::ostream& os, const Coord & c) {
    os << "(" << c.first << "; " << c.second << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Coord & c) {
    is >> c.first >> c.second;
    return is;
}
