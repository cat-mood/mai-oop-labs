#pragma once

#include <cmath>
#include <limits>
#include <iostream>

typedef std::pair<double, double> Coord;

bool operator==(Coord x, Coord y);
std::ostream& operator<<(std::ostream& os, const Coord & c);
