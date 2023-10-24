#pragma once
#include "figure.h"
#include <vector>

class Hexagon : Figure {
    friend std::ostream& operator<<(std::ostream& os, const Hexagon & h);
    friend std::istream& operator>>(std::istream& is, const Hexagon & h);
public:
    Hexagon();
    Hexagon(const std::vector<Coord> & t);
    Hexagon(const std::initializer_list<Coord> & t);
    Hexagon(Coord first, Coord second, Coord third, Coord fourth, Coord fifth, Coord sixth);
    Hexagon(const Hexagon & h);
    Hexagon(Hexagon&& h) noexcept;
    ~Hexagon();
    virtual Coord get_center() const override;
    virtual operator double() const override;
private:
    static const size_t _num_of_vertices = 6;
    std::vector<Coord> _vertices = std::vector<Coord>(_num_of_vertices);
};
