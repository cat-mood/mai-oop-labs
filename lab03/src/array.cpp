#include "array.h"

Array::Array() : _size{0}, _data{nullptr} {}

Array::Array(const std::initializer_list<Figure*> & t) {
    _size = t.size();
    _data = new Figure*[_size];
    size_t i = 0;
    for (Figure* elem : t) {
        _data[i] = elem;
        ++i;
    }
}

Array::Array(const Array & a) {
    _size = a._size;
    _data = new Figure*[_size];
    for (size_t i = 0; i < _size; ++i) {
        _data[i] = a._data[i];
    }
}

Array::Array(Array&& a) noexcept {
    _data = a._data;
    _size = a._size;
    a._data = nullptr;
    a._size = 0;
}

Array::~Array() {
    delete[] _data;
    _size = 0;
}

double Array::get_total_area() const {
    double sum = 0;
    for (size_t i = 0; i < _size; ++i) {
        sum += (double) *_data[i];
    }
    return sum;
}

size_t Array::get_size() const noexcept {
    return _size;
}

void Array::remove(size_t idx) {
    if (idx >= _size) {
        throw std::range_error("Out of range");
    }
    Figure** new_data = new Figure*[_size - 1];
    size_t j = 0;
    for (size_t i = 0; i < _size - 1; ++i) {
        if (i == idx) {
            ++j;
        }
        new_data[i] = _data[j];
        ++j;
    }
    --_size;
    delete[] _data;
    _data = new_data;
}

Figure** Array::get_data() {
    return _data;
}
