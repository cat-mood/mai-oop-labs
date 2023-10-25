#pragma once
#include "figure.h"
#include <vector>

class Hexagon : public Figure {
    friend std::ostream& operator<<(std::ostream& os, const Hexagon & h);
    friend std::istream& operator>>(std::istream& is, Hexagon & h);
public:
    Hexagon();
    Hexagon(const std::vector<Coord> & t);
    Hexagon(const std::initializer_list<Coord> & t);
    Hexagon(Coord first, Coord second, Coord third, Coord fourth, Coord fifth, Coord sixth);
    Hexagon(const Hexagon & h);
    Hexagon(Hexagon&& h) noexcept;
    ~Hexagon();
    virtual Coord get_center() const noexcept override;
    virtual operator double() const noexcept override;
    bool operator==(const Hexagon & rhs) const noexcept;
    bool operator!=(const Hexagon & rhs) const noexcept;
    bool operator>(const Hexagon & rhs) const noexcept;
    bool operator<(const Hexagon & rhs) const noexcept;
    bool operator>=(const Hexagon & rhs) const noexcept;
    bool operator<=(const Hexagon & rhs) const noexcept;
    Hexagon& operator=(const Hexagon & rhs);
    Hexagon& operator=(Hexagon&& rhs) noexcept;
private:
    static const size_t _num_of_vertices = 6;
    std::vector<Coord> _vertices = std::vector<Coord>(_num_of_vertices);
};
