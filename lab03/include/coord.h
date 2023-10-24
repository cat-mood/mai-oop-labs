#pragma once

#include <iostream>

typedef std::pair<double, double> Coord;

bool operator==(Coord x, Coord y) noexcept;
std::ostream& operator<<(std::ostream& os, const Coord & c);
std::istream& operator>>(std::istream& is, Coord & c);
