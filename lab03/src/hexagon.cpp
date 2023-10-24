#include "hexagon.h"
#include <cmath>

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

Coord Hexagon::get_center() const {
    Coord c;
    c.first = (_vertices[0].first + _vertices[3].first) / 2;    // (x1 + x4) / 2
    c.second = (_vertices[0].second + _vertices[3].second) / 2;     // (y1 + y4) / 2
    return c;
}

Hexagon::operator double() const {
    // s = 3 * sqrt(3) / 2 * ((x2 - x1)^2 + (y2 - y1)^2)
    double s = 3 * (sqrt(3) / 2) * ((_vertices[1].first - _vertices[0].first) * (_vertices[1].first - _vertices[0].first)
    + (_vertices[1].second - _vertices[0].second) * (_vertices[1].second - _vertices[0].second));
    return s;
}
