#include "coord.h"

bool operator==(Coord x, Coord y) {
    return (std::fabs(x.first - y.first) < std::numeric_limits<double>::epsilon()) 
    && (std::fabs(x.second - y.second) < std::numeric_limits<double>::epsilon());
}

std::ostream& operator<<(std::ostream& os, const Coord & c) {
    os << "x: " << c.first << "; y: " << c.second;
    return os;
}
