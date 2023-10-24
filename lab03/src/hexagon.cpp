#include "hexagon.h"
#include <cmath>

static bool is_eq(double x, double y) noexcept {
    return (std::fabs(x - y) < std::numeric_limits<double>::epsilon());
}

std::ostream& operator<<(std::ostream& os, const Hexagon & h) {
    for (Coord elem : h._vertices) {
        os << elem << " ";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Hexagon & h) {
    std::vector<Coord> v(h._num_of_vertices);
    for (Coord & elem : v) {
        is >> elem;
    }
    return is;
}

Hexagon::Hexagon() {
    for (Coord & elem : _vertices) {
        elem = std::make_pair(0, 0);
    }
}

Hexagon::Hexagon(const std::vector<Coord> & t) : _vertices(t) {}

Hexagon::Hexagon(const std::initializer_list<Coord> & t) {
    size_t i = 0;
    for (Coord elem : t) {
        _vertices[i] = elem;
        ++i;
    }
}

Hexagon::Hexagon(Coord first, Coord second, Coord third, Coord fourth, Coord fifth, Coord sixth) {
    _vertices[0] = first;
    _vertices[1] = second;
    _vertices[2] = third;
    _vertices[3] = fourth;
    _vertices[4] = fifth;
    _vertices[5] = sixth;
}

Hexagon::Hexagon(const Hexagon & h) {
    _vertices = h._vertices;
}

Hexagon::Hexagon(Hexagon&& h) noexcept {
    _vertices = std::move(h._vertices);
}

Hexagon::~Hexagon() {}

Coord Hexagon::get_center() const noexcept {
    Coord c;
    c.first = (_vertices[0].first + _vertices[3].first) / 2;    // (x1 + x4) / 2
    c.second = (_vertices[0].second + _vertices[3].second) / 2;     // (y1 + y4) / 2
    return c;
}

Hexagon::operator double() const noexcept {
    // s = 3 * sqrt(3) / 2 * ((x2 - x1)^2 + (y2 - y1)^2)
    double s = 3 * (sqrt(3) / 2) * ((_vertices[1].first - _vertices[0].first) * (_vertices[1].first - _vertices[0].first)
    + (_vertices[1].second - _vertices[0].second) * (_vertices[1].second - _vertices[0].second));
    return s;
}

bool Hexagon::operator==(const Hexagon & rhs) const noexcept {
    return is_eq((double) *this, (double) rhs);
}

bool Hexagon::operator!=(const Hexagon & rhs) const noexcept {
    return !(*this == rhs);
}

bool Hexagon::operator>(const Hexagon & rhs) const noexcept {
    return (double) *this > (double) rhs;    // спросить про сравнение < > даблов
}

bool Hexagon::operator>=(const Hexagon & rhs) const noexcept {
    return (*this > rhs) || (*this == rhs);
}

bool Hexagon::operator<=(const Hexagon & rhs) const noexcept {
    return !(*this > rhs);
}

bool Hexagon::operator<(const Hexagon & rhs) const noexcept {
    return !(*this >= rhs);
}

Hexagon& Hexagon::operator=(const Hexagon & rhs) {
    _vertices = rhs._vertices;
    return *this;
}

Hexagon& Hexagon::operator=(Hexagon&& rhs) noexcept {
    _vertices = std::move(rhs._vertices);
    return *this;
}
