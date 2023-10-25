#include "triangle.h"
#include <cmath>

const double EPS = 1e-7;

static bool is_eq(double x, double y) noexcept {
    return (std::fabs(x - y) < EPS);
}

std::ostream& operator<<(std::ostream& os, const Triangle & t) {
    for (Coord elem : t._vertices) {
        os << elem << " ";
    }
    return os;
}

std::istream& operator>>(std::istream& is, Triangle & t) {
    for (Coord & elem : t._vertices) {
        is >> elem;
    }
    return is;
}

Triangle::Triangle() {
    for (Coord & elem : _vertices) {
        elem = std::make_pair(0, 0);
    }
}

Triangle::Triangle(const Triangle & t) {
    _vertices = t._vertices;
}

Triangle::Triangle(Triangle&& t) noexcept {
    _vertices = std::move(t._vertices);
}

Triangle::Triangle(const std::initializer_list<Coord> & t) {
    size_t i = 0;
    for (Coord elem : t) {
        _vertices[i] = elem;
        ++i;
    }
}

Triangle::Triangle(Coord first, Coord second, Coord third) {
    _vertices[0] = first;
    _vertices[1] = second;
    _vertices[2] = third;
}

Triangle::Triangle(const std::vector<Coord> & t) {
    _vertices = t;
}

Triangle::~Triangle() noexcept {}

Coord Triangle::get_center() const {
    Coord c = std::make_pair(
        (_vertices[0].first + _vertices[1].first + _vertices[2].first) / 3,
        (_vertices[0].second + _vertices[1].second + _vertices[2].second) / 3
    );
    return c;
}

Triangle::operator double() const {
    Coord c = this->get_center();
    double r2 = (_vertices[0].first - c.first) * (_vertices[0].first - c.first) + (_vertices[0].second - c.second) * (_vertices[0].second - c.second);
    double s = 3 * sqrt(3) / 4 * r2;
    return s;
}

bool Triangle::operator==(const Triangle & rhs) const noexcept {
    return is_eq((double) *this, (double) rhs);
}

bool Triangle::operator!=(const Triangle & rhs) const noexcept {
    return !(*this == rhs);
}

bool Triangle::operator>(const Triangle & rhs) const noexcept {
    return ((double) *this > (double) rhs);
}

bool Triangle::operator<(const Triangle & rhs) const noexcept {
    return !(*this >= rhs);
}

bool Triangle::operator>=(const Triangle & rhs) const noexcept {
    return (*this > rhs) || (*this == rhs);
}

bool Triangle::operator<=(const Triangle & rhs) const noexcept {
    return !(*this > rhs);
}

Triangle& Triangle::operator=(const Triangle & rhs) {
    _vertices = rhs._vertices;
    return *this;
}

Triangle& Triangle::operator=(Triangle&& rhs) noexcept {
    _vertices = std::move(rhs._vertices);
    return *this;
}
