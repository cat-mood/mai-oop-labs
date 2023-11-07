#pragma once
#include "figure.h"
#include <vector>
#include <cmath>

template <class T>
class Hexagon;

template <class T>
std::ostream& operator<<(std::ostream& os, const Hexagon<T> & h);

template <class T>
std::istream& operator>>(std::istream& is, Hexagon<T> & h);

template <class T>
class Hexagon : public Figure<T> {
    friend std::ostream& operator<< <>(std::ostream& os, const Hexagon<T> & h);
    friend std::istream& operator>> <>(std::istream& is, Hexagon<T> & h);
public:
    Hexagon();
    Hexagon(const std::vector<Coord<T>> & t);
    Hexagon(const std::initializer_list<Coord<T>> & t);
    Hexagon(Coord<T> first, Coord<T> second, Coord<T> third, Coord<T> fourth, Coord<T> fifth, Coord<T> sixth);
    Hexagon(const Hexagon<T> & h);
    Hexagon(Hexagon<T>&& h) noexcept;
    ~Hexagon();
    virtual Coord<T> get_center() const noexcept override;
    virtual operator double() const noexcept override;
    bool operator==(const Hexagon<T> & rhs) const noexcept;
    bool operator!=(const Hexagon<T> & rhs) const noexcept;
    bool operator>(const Hexagon<T> & rhs) const noexcept;
    bool operator<(const Hexagon<T> & rhs) const noexcept;
    bool operator>=(const Hexagon<T> & rhs) const noexcept;
    bool operator<=(const Hexagon<T> & rhs) const noexcept;
    Hexagon<T>& operator=(const Hexagon<T> & rhs);
    Hexagon<T>& operator=(Hexagon<T>&& rhs) noexcept;
private:
    static const size_t _num_of_vertices = 6;
    std::vector<Coord<T>> _vertices = std::vector<Coord<T>>(_num_of_vertices);
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Hexagon<T> & h) {
    for (Coord<T> elem : h._vertices) {
        os << elem << " ";
    }
    return os;
}

template <class T>
std::istream& operator>>(std::istream& is, Hexagon<T> & h) {
    std::vector<Coord<T>> v(h._num_of_vertices);
    for (Coord<T> & elem : v) {
        is >> elem;
    }
    return is;
}

template <class T>
Hexagon<T>::Hexagon() {
    for (Coord<T> & elem : _vertices) {
        elem = std::make_pair(0, 0);
    }
}

template <class T>
Hexagon<T>::Hexagon(const std::vector<Coord<T>> & t) : _vertices(t) {}

template <class T>
Hexagon<T>::Hexagon(const std::initializer_list<Coord<T>> & t) {
    size_t i = 0;
    for (Coord<T> elem : t) {
        _vertices[i] = elem;
        ++i;
    }
}

template <class T>
Hexagon<T>::Hexagon(Coord<T> first, Coord<T> second, Coord<T> third, Coord<T> fourth, Coord<T> fifth, Coord<T> sixth) {
    _vertices[0] = first;
    _vertices[1] = second;
    _vertices[2] = third;
    _vertices[3] = fourth;
    _vertices[4] = fifth;
    _vertices[5] = sixth;
}

template <class T>
Hexagon<T>::Hexagon(const Hexagon<T> & h) {
    _vertices = h._vertices;
}

template <class T>
Hexagon<T>::Hexagon(Hexagon<T>&& h) noexcept {
    _vertices = std::move(h._vertices);
}

template <class T>
Hexagon<T>::~Hexagon() {}

template <class T>
Coord<T> Hexagon<T>::get_center() const noexcept {
    Coord<T> c;
    c.first = (_vertices[0].first + _vertices[3].first) / 2;    // (x1 + x4) / 2
    c.second = (_vertices[0].second + _vertices[3].second) / 2;     // (y1 + y4) / 2
    return c;
}

template <class T>
Hexagon<T>::operator double() const noexcept {
    // s = 3 * sqrt(3) / 2 * ((x2 - x1)^2 + (y2 - y1)^2)
    double s = 3 * (sqrt(3) / 2) * ((_vertices[1].first - _vertices[0].first) * (_vertices[1].first - _vertices[0].first)
    + (_vertices[1].second - _vertices[0].second) * (_vertices[1].second - _vertices[0].second));
    return s;
}

template <class T>
bool Hexagon<T>::operator==(const Hexagon<T> & rhs) const noexcept {
    return is_eq((double) *this, (double) rhs);
}

template <class T>
bool Hexagon<T>::operator!=(const Hexagon<T> & rhs) const noexcept {
    return !(*this == rhs);
}

template <class T>
bool Hexagon<T>::operator>(const Hexagon<T> & rhs) const noexcept {
    return (double) *this > (double) rhs;    // спросить про сравнение < > даблов
}

template <class T>
bool Hexagon<T>::operator>=(const Hexagon<T> & rhs) const noexcept {
    return (*this > rhs) || (*this == rhs);
}

template <class T>
bool Hexagon<T>::operator<=(const Hexagon<T> & rhs) const noexcept {
    return !(*this > rhs);
}

template <class T>
bool Hexagon<T>::operator<(const Hexagon<T> & rhs) const noexcept {
    return !(*this >= rhs);
}

template <class T>
Hexagon<T>& Hexagon<T>::operator=(const Hexagon<T> & rhs) {
    _vertices = rhs._vertices;
    return *this;
}

template <class T>
Hexagon<T>& Hexagon<T>::operator=(Hexagon<T>&& rhs) noexcept {
    _vertices = std::move(rhs._vertices);
    return *this;
}
