#include "six.h"
#include <algorithm>

Six::Six() : _size{0}, _array{nullptr} {}

Six::Six(const std::initializer_list<unsigned char> & t) {
    _array = new unsigned char[t.size()];
    _size = t.size();
    size_t i = t.size() - 1;
    for (unsigned char c : t) {
        _array[i] = c;
        i--;
    }
}

Six::Six(const std::string & t) {
    _array = new unsigned char[t.size()];
    _size = t.size();
    size_t i = t.size() - 1;
    for (unsigned char c : t) {
        _array[i] = c;
        i--;
    }
}

Six::Six(const Six & other) {
    _array = new unsigned char[other._size];
    _size = other._size;

    for (size_t i = 0; i < _size; i++) {
        _array[i] = other._array[i];
    }
}

Six::Six(Six&& other) noexcept {
    _size = other._size;
    _array = other._array;

    other._size = 0;
    other._array = nullptr;
}

Six::~Six() noexcept {
    if (_size > 0) {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}

void Six::swap(Six & other) noexcept {
    std::swap(_array, other._array);
    std::swap(_size, other._size);
}

std::ostream& Six::print(std::ostream& os) {
    size_t i = _size;
    while(i--) {
        os << _array[i];
    }
    return os;
}

size_t Six::size() const noexcept {
    return _size;
}

unsigned char* Six::array() const noexcept {
    return _array;
}

std::ostream& operator<<(std::ostream & os, const Six & t) {
    size_t i = t.size();
    while(i--) {
        os << t.array()[i];
    }
    return os;
}

bool Six::operator==(const Six & t) const {
    if (_size != t._size) {
        return false;
    }
    for (size_t i = 0; i < _size; i++) {
        if (_array[i] != t._array[i]) {
            return false;
        }
    }
    return true;
}

bool Six::operator==(const std::string & t) const {
    if (_size != t.size()) {
        return false;
    }
    size_t i = _size - 1;
    for (char c : t) {
        if (c != _array[i]) {
            return false;
        }
        --i;
    }
    return true;
}

bool Six::operator!=(const Six & t) const {
    return !(*this == t);
}

bool Six::operator!=(const std::string & t) const {
    return !(*this == t);
}

bool Six::operator>(const Six & t) const {
    if (_size != t._size) {
        return _size > t._size;
    }
    size_t i = _size;
    while(i--) {
        if (_array[i] != t._array[i]) {
            return _array[i] > t._array[i];
        }
    }
    return false;
}

bool Six::operator>=(const Six & t) const {
    return (*this > t) or (*this == t);
}

bool Six::operator<(const Six & t) const {
    return !(*this >= t);
}

bool Six::operator<=(const Six & t) const {
    return !(*this > t);
}

Six Six::operator+(const Six & t) const {
    size_t length = std::max(_size, t._size) + 1;
    std::string res(length, '0');

    for (size_t i = 0; i < length - 1; i++) {
        int sum = ((i < _size) ? _array[i] - '0' : 0) + ((i < t._size) ? t._array[i] - '0' : 0);
        res[i + 1] += (res[i] - '0' + sum) / _base;
        res[i] = (res[i] - '0' + sum) % _base + '0';
    }

    if (res[length - 1] == '0') {
        res.erase(length - 1, 1);   // erase 0 in the beginning
    }

    std::reverse(res.begin(), res.end());

    return Six(res);
}

Six Six::operator-(const Six & t) const {
    if (_size < t._size) {
        throw std::logic_error("Result can't be negative!");
    }

    if (*this == t) {
        return Six("0");
    }

    size_t length = std::max(_size, t._size);
    std::string res(length, '0');

    for (size_t i = 0; i < length - 1; i++) {
        res[i] += _array[i] - '0' - ((i < t._size) ? t._array[i] - '0' : 0);
        if (res[i] - '0' < 0) {
            res[i] += _base;
            res[i + 1] -= 1;
        }
    }
    res[length - 1] += _array[length - 1] - '0' - ((length == t._size) ? t._array[length - 1] - '0' : 0);
    if (res[length - 1] - '0' < 0) {
        throw std::logic_error("Result can't be negative!");
    }
    // erase zeros in the beginning
    int zeros = 0;
    size_t i = length - 1;
    while(res[i] == '0') {
        ++zeros;
        --i;
    }
    res.erase(length - zeros, zeros);

    std::reverse(res.begin(), res.end());

    return Six(res);
}
