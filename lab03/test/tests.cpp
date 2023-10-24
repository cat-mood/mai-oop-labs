#include "coord.h"
#include "hexagon.h"
#include <gtest/gtest.h>
#include <cmath>
#include <limits>

TEST(hex_get_center, test01) {
    Hexagon h;
    ASSERT_TRUE(h.get_center() == Coord(0, 0));
}

TEST(hex_get_center, test02) {
    Hexagon h = {Coord(0, 1), Coord(-0.8660254037844386, 0.5), Coord(-0.8660254037844386, -0.5), Coord(0, -1),
    Coord(0.8660254037844386, -0.5), Coord(0.8660254037844386, 0.5)};
    ASSERT_TRUE(h.get_center() == Coord(0, 0));
}

TEST(hex_get_center, test03) {
    Hexagon h = {Coord(-0.848076211353316, 10.12916512459885), Coord(-7.348076211353316, 7.129165124598851), Coord(-8, 0),
    Coord(-2.151923788646684, -4.129165124598851), Coord(4.348076211353316, -1.1291651245988508), Coord(5, 6)};
    ASSERT_TRUE(h.get_center() == Coord(-1.5, 3));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
