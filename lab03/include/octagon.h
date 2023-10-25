#pragma once
#include "figure.h"
#include "coord.h"
#include <vector>

class Octagon : public Figure {
    friend std::ostream& operator<<(std::ostream& os, const Octagon & o);
    friend std::istream& operator>>(std::istream& is, Octagon & o);
public:
    Octagon();
    Octagon(const Octagon & o);
    Octagon(Octagon&& o) noexcept;
    Octagon(const std::initializer_list<Coord> & t);
    Octagon(Coord first, Coord second, Coord third, Coord fourth, Coord fifth, Coord sixth, Coord seventh, Coord eighth);
    Octagon(const std::vector<Coord> & t);
    ~Octagon() noexcept;
    virtual Coord get_center() const override;
    virtual operator double() const override;
    bool operator==(const Octagon & rhs) const noexcept;
    bool operator!=(const Octagon & rhs) const noexcept;
    bool operator>(const Octagon & rhs) const noexcept;
    bool operator<(const Octagon & rhs) const noexcept;
    bool operator>=(const Octagon & rhs) const noexcept;
    bool operator<=(const Octagon & rhs) const noexcept;
    Octagon& operator=(const Octagon & rhs);
    Octagon& operator=(Octagon&& rhs) noexcept;
private:
    static const size_t _num_of_vertices = 8;
    std::vector<Coord> _vertices = std::vector<Coord>(_num_of_vertices);
};
