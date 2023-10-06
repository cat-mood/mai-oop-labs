#pragma once

#include <string>
#include <iostream>

class Six {
public:
    Six();
    Six(const std::initializer_list<unsigned char> & t);
    Six(const std::string & t);
    Six(const Six & other);
    Six(Six&& other) noexcept;
    bool operator==(const Six & t) const;
    bool operator!=(const Six & t) const;
    bool operator!=(const std::string & t) const;
    bool operator>(const Six & t) const;
    bool operator>=(const Six & t) const;
    bool operator<(const Six & t) const;
    bool operator<=(const Six & t) const;
    Six operator+(const Six & t) const;
    Six& operator+=(const Six & t);
    Six operator-(const Six & t) const;
    Six& operator-=(const Six & t);
    Six& operator=(const Six & t);
    size_t size() const noexcept;
    unsigned char* array() const noexcept;
    virtual ~Six() noexcept;
private:
    size_t _size;
    unsigned char* _array; // in reversed order
    static const int _base = 6;
};

std::ostream& operator<<(std::ostream & os, const Six & t);
