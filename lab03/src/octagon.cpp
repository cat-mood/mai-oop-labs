#include "octagon.h"
#include "coord.h"
#include <cmath>

const double EPS = 1e-7;

static bool is_eq(double x, double y) noexcept {
    return std::fabs(x - y) < EPS;
}

Octagon::Octagon() {
    for (Coord & elem : _vertices) {
        elem = std::make_pair(0, 0);
    }
}

Octagon::Octagon(const Octagon & o) {
    _vertices = o._vertices;
}

Octagon::Octagon(Octagon&& o) noexcept {
    _vertices = std::move(o._vertices);
}

Octagon::Octagon(const std::initializer_list<Coord> & t) {
    size_t i = 0;
    for (Coord elem : t) {
        _vertices[i] = elem;
        ++i;
    }
}
Octagon::Octagon(Coord first, Coord second, Coord third, Coord fourth, Coord fifth, Coord sixth, Coord seventh, Coord eighth) {
    _vertices[0] = first;
    _vertices[1] = second;
    _vertices[2] = third;
    _vertices[3] = fourth;
    _vertices[4] = fifth;
    _vertices[5] = sixth;
    _vertices[6] = seventh;
    _vertices[7] = eighth;
}

Octagon::Octagon(const std::vector<Coord> & t) {
    _vertices = t;
}

Octagon::~Octagon() noexcept {}

Coord Octagon::get_center() const {
    Coord c;
    c.first = (_vertices[0].first + _vertices[4].first) / 2;
    c.second = (_vertices[0].second + _vertices[4].second) / 2;
    return c;
}

Octagon::operator double() const {
    Coord c = this->get_center();
    double r2 = (c.first - _vertices[0].first) * (c.first - _vertices[0].first) + (c.second - _vertices[0].second) * (c.second - _vertices[0].second);
    double s = 2 * sqrt(2) * r2;
    return s;
}

std::ostream& operator<<(std::ostream& os, const Octagon & o) {
    for (Coord elem : o._vertices) {
        os << elem << " ";
    }
    return os;
}

std::istream& operator>>(std::istream& is, const Octagon & o) {
    for (Coord elem : o._vertices) {
        is >> elem;
    }
    return is;
}

bool Octagon::operator==(const Octagon & rhs) const noexcept {
    return is_eq((double) *this, (double) rhs);
}

bool Octagon::operator!=(const Octagon & rhs) const noexcept {
    return !is_eq((double) *this, (double) rhs);
}

bool Octagon::operator>(const Octagon & rhs) const noexcept {
    return (double) *this > (double) rhs;
}

bool Octagon::operator>=(const Octagon & rhs) const noexcept {
    return ((double) *this > (double) rhs) || (*this == rhs);
}

bool Octagon::operator<(const Octagon & rhs) const noexcept {
    return !(*this >= rhs);
}

bool Octagon::operator<=(const Octagon & rhs) const noexcept {
    return !(*this > rhs);
}

Octagon& Octagon::operator=(const Octagon & rhs) {
    _vertices = rhs._vertices;
    return *this;
}

Octagon& Octagon::operator=(Octagon&& rhs) noexcept {
    _vertices = std::move(rhs._vertices);
    return *this;
}
