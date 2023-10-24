#include "coord.h"

bool operator==(Coord x, Coord y) noexcept {
    return (std::fabs(x.first - y.first) < std::numeric_limits<double>::epsilon()) 
    && (std::fabs(x.second - y.second) < std::numeric_limits<double>::epsilon());
}

std::ostream& operator<<(std::ostream& os, const Coord & c) {
    os << "(" << c.first << "; " << c.second << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Coord & c) {
    is >> c.first >> c.second;
    return is;
}
