#pragma once
#include "figure.h"
#include <vector>

template <class T>
class Triangle;

template <class T>
std::ostream& operator<<(std::ostream& os, const Triangle<T> & t);

template <class T>
std::istream& operator>>(std::istream& is, Triangle<T> & t);

template <class T>
class Triangle : public Figure<T> {
    friend std::ostream& operator<< <>(std::ostream& os, const Triangle<T> & t);
    friend std::istream& operator>> <>(std::istream& is, Triangle<T> & t);
public:
    Triangle();
    Triangle(const Triangle<T> & t);
    Triangle(Triangle<T>&& t) noexcept;
    Triangle(const std::initializer_list<Coord<T>> & t);
    Triangle(Coord<T> first, Coord<T> second, Coord<T> third);
    Triangle(const std::vector<Coord<T>> & t);
    ~Triangle() noexcept;
    virtual Coord<T> get_center() const override;
    virtual operator double() const override;
    bool operator==(const Triangle<T> & rhs) const noexcept;
    bool operator!=(const Triangle<T> & rhs) const noexcept;
    bool operator>(const Triangle<T> & rhs) const noexcept;
    bool operator<(const Triangle<T> & rhs) const noexcept;
    bool operator>=(const Triangle<T> & rhs) const noexcept;
    bool operator<=(const Triangle<T> & rhs) const noexcept;
    Triangle& operator=(const Triangle<T> & rhs);
    Triangle& operator=(Triangle<T>&& rhs) noexcept;
private:
    static const size_t _num_of_vertices = 3;
    std::vector<Coord<T>> _vertices = std::vector<Coord<T>>(_num_of_vertices);
};

template <class T>
std::ostream& operator<<(std::ostream& os, const Triangle<T> & t) {
    for (Coord<T> elem : t._vertices) {
        os << elem << " ";
    }
    return os;
}

template <class T>
std::istream& operator>>(std::istream& is, Triangle<T> & t) {
    for (Coord<T> & elem : t._vertices) {
        is >> elem;
    }
    return is;
}

template <class T>
Triangle<T>::Triangle() {
    for (Coord<T> & elem : _vertices) {
        elem = std::make_pair(0, 0);
    }
}

template <class T>
Triangle<T>::Triangle(const Triangle<T> & t) {
    _vertices = t._vertices;
}

template <class T>
Triangle<T>::Triangle(Triangle<T>&& t) noexcept {
    _vertices = std::move(t._vertices);
}

template <class T>
Triangle<T>::Triangle(const std::initializer_list<Coord<T>> & t) {
    size_t i = 0;
    for (Coord<T> elem : t) {
        _vertices[i] = elem;
        ++i;
    }
}

template <class T>
Triangle<T>::Triangle(Coord<T> first, Coord<T> second, Coord<T> third) {
    _vertices[0] = first;
    _vertices[1] = second;
    _vertices[2] = third;
}

template <class T>
Triangle<T>::Triangle(const std::vector<Coord<T>> & t) {
    _vertices = t;
}

template <class T>
Triangle<T>::~Triangle() noexcept {}

template <class T>
Coord<T> Triangle<T>::get_center() const {
    Coord<T> c = std::make_pair(
        (_vertices[0].first + _vertices[1].first + _vertices[2].first) / 3,
        (_vertices[0].second + _vertices[1].second + _vertices[2].second) / 3
    );
    return c;
}

template <class T>
Triangle<T>::operator double() const {
    Coord<T> c = this->get_center();
    double r2 = (_vertices[0].first - c.first) * (_vertices[0].first - c.first) + (_vertices[0].second - c.second) * (_vertices[0].second - c.second);
    double s = 3 * sqrt(3) / 4 * r2;
    return s;
}

template <class T>
bool Triangle<T>::operator==(const Triangle<T> & rhs) const noexcept {
    return is_eq((double) *this, (double) rhs);
}

template <class T>
bool Triangle<T>::operator!=(const Triangle<T> & rhs) const noexcept {
    return !(*this == rhs);
}

template <class T>
bool Triangle<T>::operator>(const Triangle<T> & rhs) const noexcept {
    return ((double) *this > (double) rhs);
}

template <class T>
bool Triangle<T>::operator<(const Triangle<T> & rhs) const noexcept {
    return !(*this >= rhs);
}

template <class T>
bool Triangle<T>::operator>=(const Triangle<T> & rhs) const noexcept {
    return (*this > rhs) || (*this == rhs);
}

template <class T>
bool Triangle<T>::operator<=(const Triangle<T> & rhs) const noexcept {
    return !(*this > rhs);
}

template <class T>
Triangle<T>& Triangle<T>::operator=(const Triangle<T> & rhs) {
    _vertices = rhs._vertices;
    return *this;
}

template <class T>
Triangle<T>& Triangle<T>::operator=(Triangle<T>&& rhs) noexcept {
    _vertices = std::move(rhs._vertices);
    return *this;
}
