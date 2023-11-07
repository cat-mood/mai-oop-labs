#pragma once
#include "figure.h"
#include "coord.h"
#include <vector>

template <class T>
class Octagon;

template <class T>
std::ostream& operator<<(std::ostream& os, const Octagon<T> & o);

template <class T>
std::istream& operator>>(std::istream& is, Octagon<T> & o);

template <class T>
class Octagon : public Figure<T> {
    friend std::ostream& operator<< <>(std::ostream& os, const Octagon<T> & o);
    friend std::istream& operator>> <>(std::istream& is, Octagon<T> & o);
public:
    Octagon();
    Octagon(const Octagon<T> & o);
    Octagon(Octagon<T>&& o) noexcept;
    Octagon(const std::initializer_list<Coord<T>> & t);
    Octagon(Coord<T> first, Coord<T> second, Coord<T> third, Coord<T> fourth, Coord<T> fifth, Coord<T> sixth, Coord<T> seventh, Coord<T> eighth);
    Octagon(const std::vector<Coord<T>> & t);
    ~Octagon() noexcept;
    virtual Coord<T> get_center() const override;
    virtual operator double() const override;
    bool operator==(const Octagon<T> & rhs) const noexcept;
    bool operator!=(const Octagon<T> & rhs) const noexcept;
    bool operator>(const Octagon<T> & rhs) const noexcept;
    bool operator<(const Octagon<T> & rhs) const noexcept;
    bool operator>=(const Octagon<T> & rhs) const noexcept;
    bool operator<=(const Octagon<T> & rhs) const noexcept;
    Octagon& operator=(const Octagon<T> & rhs);
    Octagon& operator=(Octagon<T>&& rhs) noexcept;
private:
    static const size_t _num_of_vertices = 8;
    std::vector<Coord<T>> _vertices = std::vector<Coord<T>>(_num_of_vertices);
};

template <class T>
Octagon<T>::Octagon() {
    for (Coord<T> & elem : _vertices) {
        elem = std::make_pair(0, 0);
    }
}

template <class T>
Octagon<T>::Octagon(const Octagon<T> & o) {
    _vertices = o._vertices;
}

template <class T>
Octagon<T>::Octagon(Octagon<T>&& o) noexcept {
    _vertices = std::move(o._vertices);
}

template <class T>
Octagon<T>::Octagon(const std::initializer_list<Coord<T>> & t) {
    size_t i = 0;
    for (Coord<T> elem : t) {
        _vertices[i] = elem;
        ++i;
    }
}

template <class T>
Octagon<T>::Octagon(Coord<T> first, Coord<T> second, Coord<T> third, Coord<T> fourth, Coord<T> fifth, Coord<T> sixth, Coord<T> seventh, Coord<T> eighth) {
    _vertices[0] = first;
    _vertices[1] = second;
    _vertices[2] = third;
    _vertices[3] = fourth;
    _vertices[4] = fifth;
    _vertices[5] = sixth;
    _vertices[6] = seventh;
    _vertices[7] = eighth;
}

template <class T>
Octagon<T>::Octagon(const std::vector<Coord<T>> & t) {
    _vertices = t;
}

template <class T>
Octagon<T>::~Octagon() noexcept {}

template <class T>
Coord<T> Octagon<T>::get_center() const {
    Coord<T> c;
    c.first = (_vertices[0].first + _vertices[4].first) / 2;
    c.second = (_vertices[0].second + _vertices[4].second) / 2;
    return c;
}

template <class T>
Octagon<T>::operator double() const {
    Coord<T> c = this->get_center();
    double r2 = (c.first - _vertices[0].first) * (c.first - _vertices[0].first) + (c.second - _vertices[0].second) * (c.second - _vertices[0].second);
    double s = 2 * sqrt(2) * r2;
    return s;
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Octagon<T> & o) {
    for (Coord<T> elem : o._vertices) {
        os << elem << " ";
    }
    return os;
}

template <class T>
std::istream& operator>>(std::istream& is, Octagon<T> & o) {
    for (Coord<T> & elem : o._vertices) {
        is >> elem;
    }
    return is;
}

template <class T>
bool Octagon<T>::operator==(const Octagon<T> & rhs) const noexcept {
    return is_eq((double) *this, (double) rhs);
}

template <class T>
bool Octagon<T>::operator!=(const Octagon<T> & rhs) const noexcept {
    return !is_eq((double) *this, (double) rhs);
}

template <class T>
bool Octagon<T>::operator>(const Octagon<T> & rhs) const noexcept {
    return (double) *this > (double) rhs;
}

template <class T>
bool Octagon<T>::operator>=(const Octagon<T> & rhs) const noexcept {
    return ((double) *this > (double) rhs) || (*this == rhs);
}

template <class T>
bool Octagon<T>::operator<(const Octagon<T> & rhs) const noexcept {
    return !(*this >= rhs);
}

template <class T>
bool Octagon<T>::operator<=(const Octagon<T> & rhs) const noexcept {
    return !(*this > rhs);
}

template <class T>
Octagon<T>& Octagon<T>::operator=(const Octagon<T> & rhs) {
    _vertices = rhs._vertices;
    return *this;
}

template <class T>
Octagon<T>& Octagon<T>::operator=(Octagon<T>&& rhs) noexcept {
    _vertices = std::move(rhs._vertices);
    return *this;
}
