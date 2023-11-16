#pragma once
#include "figure.h"
#include <memory>
#include <concepts>

template <class T>
class Array {
public:
    Array();
    Array(const std::initializer_list<T> & t);
    Array(const Array<T> & a);
    Array(Array<T>&& a) noexcept;
    ~Array();
    void remove(size_t idx);
    double get_total_area() const;
    size_t get_size() const noexcept;
    void print_centers() const;
    void print_areas() const;
private:
    std::shared_ptr<T[]> _data;
    size_t _size;
};

template <class T>
Array<T>::Array() : _size{0}, _data{nullptr} {}

template <class T>
Array<T>::Array(const std::initializer_list<T> & t) {
    _size = t.size();
    _data = std::make_shared<T[]>(_size);
    size_t i = 0;
    for (T elem : t) {
        _data[i] = elem;
        ++i;
    }
}

template <class T>
Array<T>::Array(const Array<T> & a) {
    _size = a._size;
    _data = std::make_shared<T[]>(_size);
    for (size_t i = 0; i < _size; ++i) {
        _data[i] = a._data[i];
    }
}

template <class T>
Array<T>::Array(Array<T>&& a) noexcept {
    _data = a._data;
    _size = a._size;
    a._data = nullptr;
    a._size = 0;
}

template <class T>
Array<T>::~Array() {
    _size = 0;
}

template <class T>
double Array<T>::get_total_area() const {
    double sum = 0;
    for (size_t i = 0; i < _size; ++i) {
        sum += (double) *(_data[i]);
    }
    return sum;
}

template <class T>
size_t Array<T>::get_size() const noexcept {
    return _size;
}

template <class T>
void Array<T>::remove(size_t idx) {
    if (idx >= _size) {
        throw std::range_error("Out of range");
    }
    std::shared_ptr<T[]> new_data = std::make_shared<T[]>(_size - 1);
    size_t j = 0;
    for (size_t i = 0; i < _size - 1; ++i) {
        if (i == idx) {
            ++j;
        }
        new_data[i] = _data[j];
        ++j;
    }
    --_size;
    _data = new_data;
}

template <class T>
void Array<T>::print_centers() const {
    for (size_t i = 0; i < _size; ++i) {
        std::cout << _data[i]->get_center() << " ";
    }
}

template <class T>
void Array<T>::print_areas() const {
    for (size_t i = 0; i < _size; ++i) {
        std::cout << (double) *(_data[i]) << " ";
    }
}
