#include "figure.h"

class Array {
public:
    Array();
    Array(const std::initializer_list<Figure*> & t);
    Array(const Array & a);
    Array(Array&& a) noexcept;
    ~Array();
    void remove(size_t idx);
    double get_total_area() const;
    size_t get_size() const noexcept;
    Figure** get_data();
private:
    Figure** _data;
    size_t _size;
};
