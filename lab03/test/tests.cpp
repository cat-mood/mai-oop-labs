#include "coord.h"
#include "hexagon.h"
#include "octagon.h"
#include <gtest/gtest.h>
#include <cmath>

const double EPS = 1e-7;

bool is_eq(double x, double y) noexcept {
    return (std::fabs(x - y) < EPS);
}

/*------------------------HEX_GET_CENTER------------------------------------------------------------------*/

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
    Hexagon h = {Coord(0.8660254037844386, 0.5), Coord(0, 1), Coord(-0.8660254037844386, 0.5), Coord(-0.8660254037844386, -0.5), Coord(0, -1),
    Coord(0.8660254037844386, -0.5)};
    ASSERT_TRUE(h.get_center() == Coord(0, 0));
}

TEST(hex_get_center, test04) {
    Hexagon h = {Coord(123.0, 432.0), Coord(-312.62297443487745, 322.52112466548596), 
    Coord(-435.62297443487745, -109.47887533451406), Coord(-123.0, -432.0), 
    Coord(312.62297443487745, -322.52112466548596), Coord(435.62297443487745, 109.47887533451406)};
    ASSERT_TRUE(h.get_center() == Coord(0, 0));
}

TEST(hex_get_center, test05) {
    Hexagon h = {Coord(-0.848076211353316, 10.12916512459885), Coord(-7.348076211353316, 7.129165124598851), Coord(-8, 0),
    Coord(-2.151923788646684, -4.129165124598851), Coord(4.348076211353316, -1.1291651245988508), Coord(5, 6)};
    ASSERT_TRUE(h.get_center() == Coord(-1.5, 3));
}

/*------------------------------HEX_GET_AREA-----------------------------------------------------------------*/


TEST(hex_get_area, test01) {
    Hexagon h;
    ASSERT_TRUE(is_eq((double) h, 0));
}

TEST(hex_get_area, test02) {
    Hexagon h = {Coord(0, 1), Coord(-0.8660254037844386, 0.5), Coord(-0.8660254037844386, -0.5), Coord(0, -1),
    Coord(0.8660254037844386, -0.5), Coord(0.8660254037844386, 0.5)};
    ASSERT_TRUE(is_eq((double) h, 2.5980762113533156));
}

TEST(hex_get_area, test03) {
    Hexagon h = {Coord(-0.8660254037844386, -0.5), Coord(0, -1), Coord(0.8660254037844386, -0.5), 
    Coord(0.8660254037844386, 0.5), Coord(0, 1), Coord(-0.8660254037844386, 0.5)};
    ASSERT_TRUE(is_eq((double) h, 2.5980762113533156));
}

TEST(hex_get_area, test04) {
    Hexagon h = {Coord(-243.5, -198.665), Coord(-15.233731546200573, -290.2637746161375), Coord(178.22626845379943, -138.3787746161375),
    Coord(143.42000000000002, 105.10499999999999), Coord(-84.84626845379944, 196.70377461613748), Coord(-278.3062684537995, 44.81877461613749)};
    ASSERT_TRUE(is_eq((double) h, 157172.76336402984));
}

TEST(hex_get_area, test05) {
    Hexagon h = {
        Coord(7.0, 45.0), Coord(-70.07883832488648, 112.50446416709055), Coord(-167.07883832488648, 79.50446416709055), 
        Coord(-187.0, -21.0), Coord(-109.92116167511352, -88.50446416709055), 
        Coord(-12.921161675113527, -55.504464167090546)
    };
    ASSERT_TRUE(is_eq((double) h, 27274.604066787113));
}

/*-----------------------------------HEX_EQ------------------------------------------------------------------------*/

TEST(hex_eq, test01) {
    Hexagon h1 = {Coord(0, 1), Coord(-0.8660254037844386, 0.5), Coord(-0.8660254037844386, -0.5), Coord(0, -1),
    Coord(0.8660254037844386, -0.5), Coord(0.8660254037844386, 0.5)};
    Hexagon h2 = {Coord(-0.8660254037844386, -0.5), Coord(0, -1), Coord(0.8660254037844386, -0.5), 
    Coord(0.8660254037844386, 0.5), Coord(0, 1), Coord(-0.8660254037844386, 0.5)};
    ASSERT_TRUE(h1 == h2);
}

TEST(hex_eq, test02) {
    Hexagon h1, h2;
    ASSERT_TRUE(h1 == h2);
}

TEST(hex_eq, test03) {
    Hexagon h1 = {Coord(5, 0), Coord(3, 3.4641016151377544), Coord(-1, 3.4641016151377544), Coord(-3, 0), 
    Coord(-1, -3.4641016151377544), Coord(3, -3.4641016151377544)};
    Hexagon h2 = {Coord(5, 2), Coord(3, 5.464101615137754), Coord(-1, 5.464101615137754), Coord(-3, 2),
    Coord(-1, -1.4641016151377544), Coord(3, -1.4641016151377544)};
    ASSERT_TRUE(h1 == h2);
}

TEST(hex_eq, test04) {
    Hexagon h1 = {Coord(2, 0), Coord(1, 1.7320508075688772), Coord(-1, 1.7320508075688772), Coord(-2, 0),
    Coord(-1, -1.7320508075688772), Coord(1, -1.7320508075688772)};
    Hexagon h2 = {Coord(0, 2), Coord(-1.7320508075688772, 1), Coord(-1.7320508075688772, -1), Coord(0, -2),
    Coord(1.7320508075688772, -1), Coord(1.7320508075688772, 1)};
    ASSERT_TRUE(h1 == h2);
}

/*------------------------------------HEX_NOT_EQ---------------------------------------------------------*/

TEST(hex_not_eq, test01) {
    Hexagon h1 = {Coord(0, 1), Coord(-0.8660254037844386, 0.5), Coord(-0.8660254037844386, -0.5), Coord(0, -1),
    Coord(0.8660254037844386, -0.5), Coord(0.8660254037844386, 0.5)};
    Hexagon h2 = {Coord(-0.8660254037844386, -0.5), Coord(0, -1), Coord(0.8660254037844386, -0.5), 
    Coord(0.8660254037844386, 0.5), Coord(0, 1), Coord(-0.8660254037844386, 0.5)};
    ASSERT_FALSE(h1 != h2);
}

TEST(hex_not_eq, test02) {
    Hexagon h1, h2;
    ASSERT_FALSE(h1 != h2);
}

TEST(hex_not_eq, test03) {
    Hexagon h1 = {Coord(5, 0), Coord(3, 3.4641016151377544), Coord(-1, 3.4641016151377544), Coord(-3, 0), 
    Coord(-1, -3.4641016151377544), Coord(3, -3.4641016151377544)};
    Hexagon h2 = {Coord(5, 2), Coord(3, 5.464101615137754), Coord(-1, 5.464101615137754), Coord(-3, 2),
    Coord(-1, -1.4641016151377544), Coord(3, -1.4641016151377544)};
    ASSERT_FALSE(h1 != h2);
}

TEST(hex_not_eq, test04) {
    Hexagon h1 = {Coord(2, 0), Coord(1, 1.7320508075688772), Coord(-1, 1.7320508075688772), Coord(-2, 0),
    Coord(-1, -1.7320508075688772), Coord(1, -1.7320508075688772)};
    Hexagon h2 = {
        Coord(1.0, 7.0), Coord(0.6339745962155614, 5.633974596215562), Coord(1.6339745962155614, 4.633974596215562), 
        Coord(3.0, 5.0), Coord(3.3660254037844384, 6.366025403784438), Coord(2.3660254037844384, 7.366025403784438)
    };
    ASSERT_TRUE(h1 != h2);
}

/*--------------------------------------------HEX_GREATER----------------------------------------------------------*/

TEST(hex_greater, test01) {
    Hexagon h1 = {Coord(2, 0), Coord(1, 1.7320508075688772), Coord(-1, 1.7320508075688772), Coord(-2, 0),
    Coord(-1, -1.7320508075688772), Coord(1, -1.7320508075688772)};
    Hexagon h2 = {Coord(5, 0), Coord(2.5, 4.330127018922193), Coord(-2.5, 4.330127018922193), Coord(-5, 0),
    Coord(-2.5, -4.330127018922193), Coord(2.5, -4.330127018922193)};
    ASSERT_TRUE(h2 > h1);
}

TEST(hex_greater, test02) {
    Hexagon h1 = {Coord(2, 0), Coord(1, 1.7320508075688772), Coord(-1, 1.7320508075688772), Coord(-2, 0),
    Coord(-1, -1.7320508075688772), Coord(1, -1.7320508075688772)};
    Hexagon h2 = {Coord(100, 25), Coord(35.17949192431123, 97.27241335952166), Coord(-59.82050807568877, 77.27241335952166),
    Coord(-90, -15), Coord(-25.17949192431123, -87.27241335952166), Coord(69.82050807568876, -67.27241335952166)};
    ASSERT_TRUE(h2 > h1);
}

TEST(hex_greater, test03) {
    Hexagon h1 = {Coord(2, 0), Coord(1, 1.7320508075688772), Coord(-1, 1.7320508075688772), Coord(-2, 0),
    Coord(-1, -1.7320508075688772), Coord(1, -1.7320508075688772)};
    Hexagon h2 = {Coord(0, 2), Coord(-1.7320508075688772, 1), Coord(-1.7320508075688772, -1), Coord(0, -2),
    Coord(1.7320508075688772, -1), Coord(1.7320508075688772, 1)};
    ASSERT_FALSE(h2 > h1);
}

/*---------------------------------------HEX_GREATER_OR_NOT------------------------------------------------------------*/

TEST(hex_greater_or_eq, test01) {
    Hexagon h1 = {Coord(2, 0), Coord(1, 1.7320508075688772), Coord(-1, 1.7320508075688772), Coord(-2, 0),
    Coord(-1, -1.7320508075688772), Coord(1, -1.7320508075688772)};
    Hexagon h2 = {Coord(5, 0), Coord(2.5, 4.330127018922193), Coord(-2.5, 4.330127018922193), Coord(-5, 0),
    Coord(-2.5, -4.330127018922193), Coord(2.5, -4.330127018922193)};
    ASSERT_TRUE(h2 >= h1);
}

TEST(hex_greater_or_eq, test02) {
    Hexagon h1 = {Coord(2, 0), Coord(1, 1.7320508075688772), Coord(-1, 1.7320508075688772), Coord(-2, 0),
    Coord(-1, -1.7320508075688772), Coord(1, -1.7320508075688772)};
    Hexagon h2 = {Coord(100, 25), Coord(35.17949192431123, 97.27241335952166), Coord(-59.82050807568877, 77.27241335952166),
    Coord(-90, -15), Coord(-25.17949192431123, -87.27241335952166), Coord(69.82050807568876, -67.27241335952166)};
    ASSERT_TRUE(h2 >= h1);
}

TEST(hex_greater_or_eq, test03) {
    Hexagon h1 = {Coord(2, 0), Coord(1, 1.7320508075688772), Coord(-1, 1.7320508075688772), Coord(-2, 0),
    Coord(-1, -1.7320508075688772), Coord(1, -1.7320508075688772)};
    Hexagon h2 = {Coord(0, 2), Coord(-1.7320508075688772, 1), Coord(-1.7320508075688772, -1), Coord(0, -2),
    Coord(1.7320508075688772, -1), Coord(1.7320508075688772, 1)};
    ASSERT_TRUE(h2 >= h1);
}

/*------------------------------------------HEX_LESS----------------------------------------------------------*/

TEST(hex_less, test01) {
    Hexagon h1 = {Coord(2, 0), Coord(1, 1.7320508075688772), Coord(-1, 1.7320508075688772), Coord(-2, 0),
    Coord(-1, -1.7320508075688772), Coord(1, -1.7320508075688772)};
    Hexagon h2 = {Coord(5, 0), Coord(2.5, 4.330127018922193), Coord(-2.5, 4.330127018922193), Coord(-5, 0),
    Coord(-2.5, -4.330127018922193), Coord(2.5, -4.330127018922193)};
    ASSERT_FALSE(h2 < h1);
}

TEST(hex_less, test02) {
    Hexagon h1 = {Coord(2, 0), Coord(1, 1.7320508075688772), Coord(-1, 1.7320508075688772), Coord(-2, 0),
    Coord(-1, -1.7320508075688772), Coord(1, -1.7320508075688772)};
    Hexagon h2 = {Coord(100, 25), Coord(35.17949192431123, 97.27241335952166), Coord(-59.82050807568877, 77.27241335952166),
    Coord(-90, -15), Coord(-25.17949192431123, -87.27241335952166), Coord(69.82050807568876, -67.27241335952166)};
    ASSERT_FALSE(h2 < h1);
}

TEST(hex_less, test03) {
    Hexagon h1 = {Coord(2, 0), Coord(1, 1.7320508075688772), Coord(-1, 1.7320508075688772), Coord(-2, 0),
    Coord(-1, -1.7320508075688772), Coord(1, -1.7320508075688772)};
    Hexagon h2 = {Coord(0, 2), Coord(-1.7320508075688772, 1), Coord(-1.7320508075688772, -1), Coord(0, -2),
    Coord(1.7320508075688772, -1), Coord(1.7320508075688772, 1)};
    ASSERT_FALSE(h2 < h1);
}

/*-----------------------------------------HEX_LESS_OR_EQ----------------------------------------------------*/

TEST(hex_less_or_eq, test01) {
    Hexagon h1 = {Coord(2, 0), Coord(1, 1.7320508075688772), Coord(-1, 1.7320508075688772), Coord(-2, 0),
    Coord(-1, -1.7320508075688772), Coord(1, -1.7320508075688772)};
    Hexagon h2 = {Coord(5, 0), Coord(2.5, 4.330127018922193), Coord(-2.5, 4.330127018922193), Coord(-5, 0),
    Coord(-2.5, -4.330127018922193), Coord(2.5, -4.330127018922193)};
    ASSERT_FALSE(h2 <= h1);
}

TEST(hex_less_or_eq, test02) {
    Hexagon h1 = {Coord(2, 0), Coord(1, 1.7320508075688772), Coord(-1, 1.7320508075688772), Coord(-2, 0),
    Coord(-1, -1.7320508075688772), Coord(1, -1.7320508075688772)};
    Hexagon h2 = {Coord(100, 25), Coord(35.17949192431123, 97.27241335952166), Coord(-59.82050807568877, 77.27241335952166),
    Coord(-90, -15), Coord(-25.17949192431123, -87.27241335952166), Coord(69.82050807568876, -67.27241335952166)};
    ASSERT_FALSE(h2 <= h1);
}

TEST(hex_less_or_eq, test03) {
    Hexagon h1 = {Coord(2, 0), Coord(1, 1.7320508075688772), Coord(-1, 1.7320508075688772), Coord(-2, 0),
    Coord(-1, -1.7320508075688772), Coord(1, -1.7320508075688772)};
    Hexagon h2 = {Coord(0, 2), Coord(-1.7320508075688772, 1), Coord(-1.7320508075688772, -1), Coord(0, -2),
    Coord(1.7320508075688772, -1), Coord(1.7320508075688772, 1)};
    ASSERT_TRUE(h2 <= h1);
}

/*---------------------------------HEX_OP_COPY--------------------------------------------------------------------*/

TEST(hex_op_copy, test01) {
    Hexagon h1;
    Hexagon h2 = {Coord(2, 0), Coord(1, 1.7320508075688772), Coord(-1, 1.7320508075688772), Coord(-2, 0),
    Coord(-1, -1.7320508075688772), Coord(1, -1.7320508075688772)};
    h1 = h2;
    ASSERT_TRUE(h1 == h2);
}

TEST(hex_op_copy, test02) {
    Hexagon h1;
    Hexagon h2 = {Coord(2, 0), Coord(1, 1.7320508075688772), Coord(-1, 1.7320508075688772), Coord(-2, 0),
    Coord(-1, -1.7320508075688772), Coord(1, -1.7320508075688772)};
    h2 = h1;
    ASSERT_TRUE(h1 == h2);
}

TEST(hex_op_copy, test03) {
    Hexagon h1 = {Coord(100, 25), Coord(35.17949192431123, 97.27241335952166), Coord(-59.82050807568877, 77.27241335952166),
    Coord(-90, -15), Coord(-25.17949192431123, -87.27241335952166), Coord(69.82050807568876, -67.27241335952166)};
    Hexagon h2(Coord(2, 0), Coord(1, 1.7320508075688772), Coord(-1, 1.7320508075688772), Coord(-2, 0),
    Coord(-1, -1.7320508075688772), Coord(1, -1.7320508075688772));
    h1 = h2;
    ASSERT_TRUE(h1 == h2);
}

/*--------------------------------------HEX_OP_MOVE--------------------------------------------------------------*/

TEST(hex_op_move, test01) {
    Hexagon h1;
    Hexagon h2 = {Coord(2, 0), Coord(1, 1.7320508075688772), Coord(-1, 1.7320508075688772), Coord(-2, 0),
    Coord(-1, -1.7320508075688772), Coord(1, -1.7320508075688772)};
    Hexagon h3(h2);
    h1 = std::move(h2);
    ASSERT_TRUE(h1 == h3);
}

TEST(hex_op_move, test02) {
    Hexagon h1;
    Hexagon h2 = {Coord(2, 0), Coord(1, 1.7320508075688772), Coord(-1, 1.7320508075688772), Coord(-2, 0),
    Coord(-1, -1.7320508075688772), Coord(1, -1.7320508075688772)};
    h2 = std::move(h1);
    ASSERT_TRUE(h2 == Hexagon());
}

TEST(hex_op_move, test03) {
    Hexagon h1 = {Coord(100, 25), Coord(35.17949192431123, 97.27241335952166), Coord(-59.82050807568877, 77.27241335952166),
    Coord(-90, -15), Coord(-25.17949192431123, -87.27241335952166), Coord(69.82050807568876, -67.27241335952166)};
    Hexagon h2(Coord(2, 0), Coord(1, 1.7320508075688772), Coord(-1, 1.7320508075688772), Coord(-2, 0),
    Coord(-1, -1.7320508075688772), Coord(1, -1.7320508075688772));
    Hexagon h3(h2);
    h1 = std::move(h2);
    ASSERT_TRUE(h1 == h3);
}

/*--------------------------------------OCT_GET_CENTER-------------------------------------------------------------*/

TEST(oct_get_center, test01) {
    Octagon o;
    ASSERT_TRUE(o.get_center() == Coord(0, 0));
}

TEST(oct_get_center, test02) {
    Octagon o = {Coord(0, 2), Coord(-1.414213562373095, 1.4142135623730951), Coord(-2, 1.2246467991473532e-16), 
    Coord(-1.4142135623730951, -1.414213562373095), Coord(-2.4492935982947064e-16, -2), Coord(1.414213562373095, -1.4142135623730954),
    Coord(2, -3.6739403974420594e-16), Coord(1.4142135623730954, 1.4142135623730947)};
    ASSERT_TRUE(o.get_center() == Coord(0, 0));
}

TEST(oct_get_center, test03) {
    Octagon o = {Coord(-1.414213562373095, 1.4142135623730951), Coord(-2, 1.2246467991473532e-16), 
    Coord(-1.4142135623730951, -1.414213562373095), Coord(-2.4492935982947064e-16, -2), Coord(1.414213562373095, -1.4142135623730954),
    Coord(2, -3.6739403974420594e-16), Coord(1.4142135623730954, 1.4142135623730947), Coord(0, 2)};
    ASSERT_TRUE(o.get_center() == Coord(0, 0));
}

TEST(oct_get_center, test04) {
    Octagon o = {
        Coord(-46.0, 175.0), Coord(-156.270598642227, 91.21677477306463), 
        Coord(-175.0, -45.999999999999986), Coord(-91.21677477306463, -156.270598642227), 
        Coord(45.99999999999998, -175.0), Coord(156.27059864222701, -91.21677477306466), 
        Coord(175.0, 45.999999999999964), Coord(91.21677477306467, 156.270598642227)
    };
    ASSERT_TRUE(o.get_center() == Coord(0, 0));
}

TEST(oct_get_center, test05) {
    Octagon o = {
        Coord(-566.0, 23.0), Coord(-470.9747468305833, -426.41125496954277), 
        Coord(-86.00000000000003, -677.0), Coord(363.41125496954277, -581.9747468305833), 
        Coord(614.0, -197.00000000000006), Coord(518.9747468305833, 252.41125496954277), 
        Coord(134.0000000000001, 503.0), Coord(-315.4112549695427, 407.9747468305833)
    };
    ASSERT_TRUE(o.get_center() == Coord(24, -87));
}

/*-----------------------------------OCT_GET_AREA-------------------------------------------------------------------*/

TEST(oct_get_area, test01) {
    Octagon o;
    ASSERT_TRUE(is_eq((double) o, 0));
}

TEST(oct_get_area, test02) {
    Octagon o = {
        Coord(10.0, -10.0), Coord(14.142135623730951, -8.881784197001252e-16), Coord(10.0, 10.0), 
        Coord(8.881784197001252e-16, 14.142135623730951), Coord(-9.999999999999998, 10.000000000000002), 
        Coord(-14.142135623730951, 2.6645352591003757e-15), Coord(-10.000000000000002, -9.999999999999998), 
        Coord(-3.552713678800501e-15, -14.142135623730951)
    };
    ASSERT_TRUE(is_eq((double) o, 565.685424949238));
}

TEST(oct_get_area, test03) {
    Octagon o = {
        Coord(14.142135623730951, -8.881784197001252e-16), Coord(10.0, 10.0), 
        Coord(8.881784197001252e-16, 14.142135623730951), Coord(-9.999999999999998, 10.000000000000002), 
        Coord(-14.142135623730951, 2.6645352591003757e-15), Coord(-10.000000000000002, -9.999999999999998), 
        Coord(-3.552713678800501e-15, -14.142135623730951), Coord(10.0, -10.0)
    };
    ASSERT_TRUE(is_eq((double) o, 565.685424949238));
}

TEST(oct_get_area, test04) {
    Octagon o = {
        Coord(1.0, 2.0), Coord(-0.7071067811865474, 2.121320343559643), Coord(-2.0, 1.0000000000000002), 
        Coord(-2.121320343559643, -0.7071067811865474), Coord(-1.0000000000000002, -1.9999999999999998), 
        Coord(0.7071067811865472, -2.121320343559643), Coord(1.9999999999999998, -1.0000000000000004), 
        Coord(2.121320343559643, 0.707106781186547)
    };
    ASSERT_TRUE(is_eq((double) o, 14.142135623730951));
}

TEST(oct_get_area, test05) {
    Octagon o = {
        Coord(17.0, -69.0), Coord(122.10764773832473, -4.75230867899738), Coord(151.0, 114.99999999999999), 
        Coord(86.75230867899738, 220.10764773832472), Coord(-32.99999999999998, 249.0), 
        Coord(-138.10764773832474, 184.7523086789974), Coord(-167.0, 65.00000000000003), 
        Coord(-102.7523086789974, -40.107647738324715)
    };
    ASSERT_TRUE(is_eq((double) o, 73273.2330936748));
}

/*---------------------------------------OCT_EQ--------------------------------------------------------------------*/

TEST(oct_eq, test01) {
    Octagon o1 = {
        Coord(4.0, -2.0), Coord(4.242640687119286, 1.4142135623730947), Coord(2.0000000000000004, 4.0), 
        Coord(-1.4142135623730947, 4.242640687119286), Coord(-3.9999999999999996, 2.0000000000000004), 
        Coord(-4.242640687119286, -1.4142135623730945), Coord(-2.000000000000001, -3.9999999999999996), 
        Coord(1.414213562373094, -4.242640687119286)
    };
    Octagon o2 = {
        Coord(4.242640687119286, 1.4142135623730947), Coord(2.0000000000000004, 4.0), 
        Coord(-1.4142135623730947, 4.242640687119286), Coord(-3.9999999999999996, 2.0000000000000004), 
        Coord(-4.242640687119286, -1.4142135623730945), Coord(-2.000000000000001, -3.9999999999999996), 
        Coord(1.414213562373094, -4.242640687119286), Coord(4.0, -2.0)
    };
    ASSERT_TRUE(o1 == o2);
}

TEST(oct_eq, test02) {
    Octagon o1, o2;
    ASSERT_TRUE(o1 == o2);
}

TEST(oct_eq, test03) {
    Octagon o1 = {
        Coord(1.0, -2.0), Coord(7.414213562373094, -3.48528137423857), Coord(13.0, -4.286263797015736e-16), 
        Coord(14.485281374238571, 6.414213562373094), Coord(11.0, 12.0), Coord(4.585786437626906, 13.485281374238571), 
        Coord(-0.9999999999999991, 10.000000000000002), Coord(-2.4852813742385704, 3.585786437626906)
    };
    Octagon o2 = {
        Coord(-2.0, -5.0), Coord(4.414213562373094, -6.4852813742385695), Coord(10.0, -3.0000000000000004), 
        Coord(11.485281374238571, 3.414213562373094), Coord(8.0, 9.0), Coord(1.5857864376269069, 10.485281374238571), 
        Coord(-3.999999999999999, 7.000000000000001), Coord(-5.48528137423857, 0.5857864376269069)
    };
    ASSERT_TRUE(o1 == o2);
}

TEST(oct_eq, test04) {
    Octagon o1 = {
        Coord(2.0, 0.0), Coord(1.4142135623730951, 1.414213562373095), Coord(1.2246467991473532e-16, 2.0), 
        Coord(-1.414213562373095, 1.4142135623730951), Coord(-2.0, 2.4492935982947064e-16), 
        Coord(-1.4142135623730954, -1.414213562373095), Coord(-3.6739403974420594e-16, -2.0), 
        Coord(1.4142135623730947, -1.4142135623730954)
    };
    Octagon o2 = {
        Coord(0.0, 2.0), Coord(-1.414213562373095, 1.4142135623730951), Coord(-2.0, 1.2246467991473532e-16), 
        Coord(-1.4142135623730951, -1.414213562373095), Coord(-2.4492935982947064e-16, -2.0), 
        Coord(1.414213562373095, -1.4142135623730954), Coord(2.0, -3.6739403974420594e-16), 
        Coord(1.4142135623730954, 1.4142135623730947)
    };
    ASSERT_TRUE(o1 == o2);
}

/*-------------------------------------OCT_NOT_EQ------------------------------------------------------------*/

TEST(oct_not_eq, test01) {
    Octagon o1 = {
        Coord(4.0, -2.0), Coord(4.242640687119286, 1.4142135623730947), Coord(2.0000000000000004, 4.0), 
        Coord(-1.4142135623730947, 4.242640687119286), Coord(-3.9999999999999996, 2.0000000000000004), 
        Coord(-4.242640687119286, -1.4142135623730945), Coord(-2.000000000000001, -3.9999999999999996), 
        Coord(1.414213562373094, -4.242640687119286)
    };
    Octagon o2 = {
        Coord(4.242640687119286, 1.4142135623730947), Coord(2.0000000000000004, 4.0), 
        Coord(-1.4142135623730947, 4.242640687119286), Coord(-3.9999999999999996, 2.0000000000000004), 
        Coord(-4.242640687119286, -1.4142135623730945), Coord(-2.000000000000001, -3.9999999999999996), 
        Coord(1.414213562373094, -4.242640687119286), Coord(4.0, -2.0)
    };
    ASSERT_FALSE(o1 != o2);
}

TEST(oct_not_eq, test02) {
    Octagon o1, o2 = {
        Coord(4.242640687119286, 1.4142135623730947), Coord(2.0000000000000004, 4.0), 
        Coord(-1.4142135623730947, 4.242640687119286), Coord(-3.9999999999999996, 2.0000000000000004), 
        Coord(-4.242640687119286, -1.4142135623730945), Coord(-2.000000000000001, -3.9999999999999996), 
        Coord(1.414213562373094, -4.242640687119286), Coord(4.0, -2.0)
    };
    ASSERT_TRUE(o1 != o2);
}

TEST(oct_not_eq, test03) {
    Octagon o1 = {
        Coord(1.0, -2.0), Coord(7.414213562373094, -3.48528137423857), Coord(13.0, -4.286263797015736e-16), 
        Coord(14.485281374238571, 6.414213562373094), Coord(11.0, 12.0), Coord(4.585786437626906, 13.485281374238571), 
        Coord(-0.9999999999999991, 10.000000000000002), Coord(-2.4852813742385704, 3.585786437626906)
    };
    Octagon o2 = {
        Coord(-2.0, -5.0), Coord(4.414213562373094, -6.4852813742385695), Coord(10.0, -3.0000000000000004), 
        Coord(11.485281374238571, 3.414213562373094), Coord(8.0, 9.0), Coord(1.5857864376269069, 10.485281374238571), 
        Coord(-3.999999999999999, 7.000000000000001), Coord(-5.48528137423857, 0.5857864376269069)
    };
    ASSERT_FALSE(o1 != o2);
}

TEST(oct_not_eq, test04) {
    Octagon o1 = {
        Coord(9.8, -3.0), Coord(8.945941546018393, 5.261879502661796), Coord(2.500000000000001, 10.5), 
        Coord(-5.761879502661796, 9.645941546018392), Coord(-11.0, 3.2000000000000015), 
        Coord(-10.145941546018392, -5.061879502661796), Coord(-3.700000000000002, -10.3), 
        Coord(4.561879502661796, -9.445941546018393)
    };
    Octagon o2 = {
        Coord(6.4, 0.888), Coord(27.35341670061596, 16.525977223318037), Coord(31.112000000000002, 42.4), 
        Coord(15.474022776681966, 63.353416700615966), Coord(-10.399999999999997, 67.112), 
        Coord(-31.353416700615963, 51.47402277668197), Coord(-35.112, 25.60000000000001), 
        Coord(-19.47402277668197, 4.646583299384041)
    };
    ASSERT_TRUE(o1 != o2);
}


/*---------------------------------------------OCT_GREATER---------------------------------------------------------*/

TEST(oct_greater, test01) {
    Octagon o1 = {
        Coord(2.2, 0.0), Coord(1.5556349186104048, 1.5556349186104046), Coord(1.3471114790620887e-16, 2.2), 
        Coord(-1.5556349186104046, 1.5556349186104048), Coord(-2.2, 2.6942229581241775e-16), 
        Coord(-1.555634918610405, -1.5556349186104046), Coord(-4.0413344371862655e-16, -2.2), 
        Coord(1.5556349186104044, -1.555634918610405)
    };
    Octagon o2 = {
        Coord(4.5, 0.0), Coord(3.1819805153394642, 3.181980515339464), Coord(2.755455298081545e-16, 4.5), 
        Coord(-3.181980515339464, 3.1819805153394642), Coord(-4.5, 5.51091059616309e-16), 
        Coord(-3.1819805153394647, -3.181980515339464), Coord(-8.266365894244633e-16, -4.5), 
        Coord(3.181980515339463, -3.1819805153394647)
    };
    ASSERT_TRUE(o2 > o1);
}

TEST(oct_greater, test02) {
    Octagon o1 = {
        Coord(4.3, -2.2), Coord(5.596194077712559, 1.0707106781186542), Coord(4.2, 4.3), 
        Coord(0.9292893218813458, 5.596194077712559), Coord(-2.2999999999999994, 4.200000000000001), 
        Coord(-3.596194077712559, 0.9292893218813458), Coord(-2.2000000000000006, -2.2999999999999994), 
        Coord(1.0707106781186537, -3.5961940777125587)
    };
    Octagon o2 = {
        Coord(900.0, 230.4), Coord(473.40763287064686, 793.4850783285272), Coord(-226.39999999999995, 890.0), 
        Coord(-789.4850783285272, 463.40763287064686), Coord(-886.0, -236.3999999999999), 
        Coord(-459.40763287064686, -799.4850783285272), Coord(240.39999999999984, -896.0), 
        Coord(803.485078328527, -469.4076328706469)
    };
    ASSERT_TRUE(o2 > o1);
}

TEST(oct_greater, test03) {
    Octagon o1 = {
        Coord(4.2, 0.0), Coord(2.9698484809835, 2.9698484809834995), Coord(2.571758278209442e-16, 4.2), 
        Coord(-2.9698484809834995, 2.9698484809835), Coord(-4.2, 5.143516556418884e-16), 
        Coord(-2.9698484809835004, -2.9698484809834995), Coord(-7.715274834628325e-16, -4.2), 
        Coord(2.969848480983499, -2.9698484809835004)
    };
    Octagon o2 = {
        Coord(0.0, 4.2), Coord(-2.9698484809834995, 2.9698484809835), Coord(-4.2, 2.571758278209442e-16), 
        Coord(-2.9698484809835, -2.9698484809834995), Coord(-5.143516556418884e-16, -4.2), 
        Coord(2.9698484809834995, -2.9698484809835004), Coord(4.2, -7.715274834628325e-16), 
        Coord(2.9698484809835004, 2.969848480983499)
    };
    ASSERT_FALSE(o2 > o1);
}

/*-------------------------------------------OCT_GREATER_OR_EQ--------------------------------------------------*/

TEST(oct_greater_or_eq, test01) {
    Octagon o1 = {
        Coord(2.2, 0.0), Coord(1.5556349186104048, 1.5556349186104046), Coord(1.3471114790620887e-16, 2.2), 
        Coord(-1.5556349186104046, 1.5556349186104048), Coord(-2.2, 2.6942229581241775e-16), 
        Coord(-1.555634918610405, -1.5556349186104046), Coord(-4.0413344371862655e-16, -2.2), 
        Coord(1.5556349186104044, -1.555634918610405)
    };
    Octagon o2 = {
        Coord(4.5, 0.0), Coord(3.1819805153394642, 3.181980515339464), Coord(2.755455298081545e-16, 4.5), 
        Coord(-3.181980515339464, 3.1819805153394642), Coord(-4.5, 5.51091059616309e-16), 
        Coord(-3.1819805153394647, -3.181980515339464), Coord(-8.266365894244633e-16, -4.5), 
        Coord(3.181980515339463, -3.1819805153394647)
    };
    ASSERT_TRUE(o2 >= o1);
}

TEST(oct_greater_or_eq, test02) {
    Octagon o1 = {
        Coord(4.3, -2.2), Coord(5.596194077712559, 1.0707106781186542), Coord(4.2, 4.3), 
        Coord(0.9292893218813458, 5.596194077712559), Coord(-2.2999999999999994, 4.200000000000001), 
        Coord(-3.596194077712559, 0.9292893218813458), Coord(-2.2000000000000006, -2.2999999999999994), 
        Coord(1.0707106781186537, -3.5961940777125587)
    };
    Octagon o2 = {
        Coord(900.0, 230.4), Coord(473.40763287064686, 793.4850783285272), Coord(-226.39999999999995, 890.0), 
        Coord(-789.4850783285272, 463.40763287064686), Coord(-886.0, -236.3999999999999), 
        Coord(-459.40763287064686, -799.4850783285272), Coord(240.39999999999984, -896.0), 
        Coord(803.485078328527, -469.4076328706469)
    };
    ASSERT_TRUE(o2 >= o1);
}

TEST(oct_greater_or_eq, test03) {
    Octagon o1 = {
        Coord(4.2, 0.0), Coord(2.9698484809835, 2.9698484809834995), Coord(2.571758278209442e-16, 4.2), 
        Coord(-2.9698484809834995, 2.9698484809835), Coord(-4.2, 5.143516556418884e-16), 
        Coord(-2.9698484809835004, -2.9698484809834995), Coord(-7.715274834628325e-16, -4.2), 
        Coord(2.969848480983499, -2.9698484809835004)
    };
    Octagon o2 = {
        Coord(0.0, 4.2), Coord(-2.9698484809834995, 2.9698484809835), Coord(-4.2, 2.571758278209442e-16), 
        Coord(-2.9698484809835, -2.9698484809834995), Coord(-5.143516556418884e-16, -4.2), 
        Coord(2.9698484809834995, -2.9698484809835004), Coord(4.2, -7.715274834628325e-16), 
        Coord(2.9698484809835004, 2.969848480983499)
    };
    ASSERT_TRUE(o2 >= o1);
}

/*-------------------------------------------OCT_LESS-------------------------------------------------------*/

TEST(oct_less, test01) {
    Octagon o1 = {
        Coord(2.2, 0.0), Coord(1.5556349186104048, 1.5556349186104046), Coord(1.3471114790620887e-16, 2.2), 
        Coord(-1.5556349186104046, 1.5556349186104048), Coord(-2.2, 2.6942229581241775e-16), 
        Coord(-1.555634918610405, -1.5556349186104046), Coord(-4.0413344371862655e-16, -2.2), 
        Coord(1.5556349186104044, -1.555634918610405)
    };
    Octagon o2 = {
        Coord(4.5, 0.0), Coord(3.1819805153394642, 3.181980515339464), Coord(2.755455298081545e-16, 4.5), 
        Coord(-3.181980515339464, 3.1819805153394642), Coord(-4.5, 5.51091059616309e-16), 
        Coord(-3.1819805153394647, -3.181980515339464), Coord(-8.266365894244633e-16, -4.5), 
        Coord(3.181980515339463, -3.1819805153394647)
    };
    ASSERT_TRUE(o1 < o2);
}

TEST(oct_less, test02) {
    Octagon o1 = {
        Coord(4.3, -2.2), Coord(5.596194077712559, 1.0707106781186542), Coord(4.2, 4.3), 
        Coord(0.9292893218813458, 5.596194077712559), Coord(-2.2999999999999994, 4.200000000000001), 
        Coord(-3.596194077712559, 0.9292893218813458), Coord(-2.2000000000000006, -2.2999999999999994), 
        Coord(1.0707106781186537, -3.5961940777125587)
    };
    Octagon o2 = {
        Coord(900.0, 230.4), Coord(473.40763287064686, 793.4850783285272), Coord(-226.39999999999995, 890.0), 
        Coord(-789.4850783285272, 463.40763287064686), Coord(-886.0, -236.3999999999999), 
        Coord(-459.40763287064686, -799.4850783285272), Coord(240.39999999999984, -896.0), 
        Coord(803.485078328527, -469.4076328706469)
    };
    ASSERT_TRUE(o1 < o2);
}

TEST(oct_less, test03) {
    Octagon o1 = {
        Coord(4.2, 0.0), Coord(2.9698484809835, 2.9698484809834995), Coord(2.571758278209442e-16, 4.2), 
        Coord(-2.9698484809834995, 2.9698484809835), Coord(-4.2, 5.143516556418884e-16), 
        Coord(-2.9698484809835004, -2.9698484809834995), Coord(-7.715274834628325e-16, -4.2), 
        Coord(2.969848480983499, -2.9698484809835004)
    };
    Octagon o2 = {
        Coord(0.0, 4.2), Coord(-2.9698484809834995, 2.9698484809835), Coord(-4.2, 2.571758278209442e-16), 
        Coord(-2.9698484809835, -2.9698484809834995), Coord(-5.143516556418884e-16, -4.2), 
        Coord(2.9698484809834995, -2.9698484809835004), Coord(4.2, -7.715274834628325e-16), 
        Coord(2.9698484809835004, 2.969848480983499)
    };
    ASSERT_FALSE(o1 < o2);
}

/*----------------------------------------OCT_LESS_OR_EQ---------------------------------------------------------*/

TEST(oct_less_or_eq, test01) {
    Octagon o1 = {
        Coord(2.2, 0.0), Coord(1.5556349186104048, 1.5556349186104046), Coord(1.3471114790620887e-16, 2.2), 
        Coord(-1.5556349186104046, 1.5556349186104048), Coord(-2.2, 2.6942229581241775e-16), 
        Coord(-1.555634918610405, -1.5556349186104046), Coord(-4.0413344371862655e-16, -2.2), 
        Coord(1.5556349186104044, -1.555634918610405)
    };
    Octagon o2 = {
        Coord(4.5, 0.0), Coord(3.1819805153394642, 3.181980515339464), Coord(2.755455298081545e-16, 4.5), 
        Coord(-3.181980515339464, 3.1819805153394642), Coord(-4.5, 5.51091059616309e-16), 
        Coord(-3.1819805153394647, -3.181980515339464), Coord(-8.266365894244633e-16, -4.5), 
        Coord(3.181980515339463, -3.1819805153394647)
    };
    ASSERT_TRUE(o1 <= o2);
}

TEST(oct_less_or_eq, test02) {
    Octagon o1 = {
        Coord(4.3, -2.2), Coord(5.596194077712559, 1.0707106781186542), Coord(4.2, 4.3), 
        Coord(0.9292893218813458, 5.596194077712559), Coord(-2.2999999999999994, 4.200000000000001), 
        Coord(-3.596194077712559, 0.9292893218813458), Coord(-2.2000000000000006, -2.2999999999999994), 
        Coord(1.0707106781186537, -3.5961940777125587)
    };
    Octagon o2 = {
        Coord(900.0, 230.4), Coord(473.40763287064686, 793.4850783285272), Coord(-226.39999999999995, 890.0), 
        Coord(-789.4850783285272, 463.40763287064686), Coord(-886.0, -236.3999999999999), 
        Coord(-459.40763287064686, -799.4850783285272), Coord(240.39999999999984, -896.0), 
        Coord(803.485078328527, -469.4076328706469)
    };
    ASSERT_TRUE(o1 <= o2);
}

TEST(oct_less_or_eq, test03) {
    Octagon o1 = {
        Coord(4.2, 0.0), Coord(2.9698484809835, 2.9698484809834995), Coord(2.571758278209442e-16, 4.2), 
        Coord(-2.9698484809834995, 2.9698484809835), Coord(-4.2, 5.143516556418884e-16), 
        Coord(-2.9698484809835004, -2.9698484809834995), Coord(-7.715274834628325e-16, -4.2), 
        Coord(2.969848480983499, -2.9698484809835004)
    };
    Octagon o2 = {
        Coord(0.0, 4.2), Coord(-2.9698484809834995, 2.9698484809835), Coord(-4.2, 2.571758278209442e-16), 
        Coord(-2.9698484809835, -2.9698484809834995), Coord(-5.143516556418884e-16, -4.2), 
        Coord(2.9698484809834995, -2.9698484809835004), Coord(4.2, -7.715274834628325e-16), 
        Coord(2.9698484809835004, 2.969848480983499)
    };
    ASSERT_TRUE(o1 <= o2);
}

/*--------------------------------------------OCT_OP_COPY--------------------------------------------------------*/

TEST(oct_op_copy, test01) {
    Octagon o1;
    Octagon o2 = {
        Coord(4.2, 0.0), Coord(2.9698484809835, 2.9698484809834995), Coord(2.571758278209442e-16, 4.2), 
        Coord(-2.9698484809834995, 2.9698484809835), Coord(-4.2, 5.143516556418884e-16), 
        Coord(-2.9698484809835004, -2.9698484809834995), Coord(-7.715274834628325e-16, -4.2), 
        Coord(2.969848480983499, -2.9698484809835004)
    };
    o1 = o2;
    ASSERT_TRUE(o1 == o2);
}

TEST(oct_op_copy, test02) {
    Octagon o1;
    Octagon o2 = {
        Coord(4.2, 0.0), Coord(2.9698484809835, 2.9698484809834995), Coord(2.571758278209442e-16, 4.2), 
        Coord(-2.9698484809834995, 2.9698484809835), Coord(-4.2, 5.143516556418884e-16), 
        Coord(-2.9698484809835004, -2.9698484809834995), Coord(-7.715274834628325e-16, -4.2), 
        Coord(2.969848480983499, -2.9698484809835004)
    };
    o2 = o1;
    ASSERT_TRUE(o1 == o2);
}

TEST(oct_op_copy, test03) {
    Octagon o1 = {
        Coord(2.3, -0.9), Coord(1.777460325558382, -5.838477631085023), Coord(4.9, -9.7), 
        Coord(9.838477631085023, -10.222539674441617), Coord(13.7, -7.100000000000001), 
        Coord(14.222539674441618, -2.161522368914977), Coord(11.100000000000001, 1.6999999999999995), 
        Coord(6.161522368914978, 2.222539674441619)
    };
    Octagon o2 = {
        Coord(5.0, 0.0), Coord(9.596551211459378, 7.702943725152284), Coord(7.4, 16.4), 
        Coord(-0.30294372515228396, 20.996551211459376), Coord(-8.999999999999998, 18.8), 
        Coord(-13.59655121145938, 11.097056274847716), Coord(-11.400000000000002, 2.400000000000002), 
        Coord(-3.697056274847717, -2.1965512114593784)
    };
    o1 = o2;
    ASSERT_TRUE(o1 == o2);
}

/*------------------------------------------OCT_OP_MOVE-----------------------------------------------------------*/

TEST(oct_op_move, test01) {
    Octagon o1;
    Octagon o2 = {
        Coord(4.2, 0.0), Coord(2.9698484809835, 2.9698484809834995), Coord(2.571758278209442e-16, 4.2), 
        Coord(-2.9698484809834995, 2.9698484809835), Coord(-4.2, 5.143516556418884e-16), 
        Coord(-2.9698484809835004, -2.9698484809834995), Coord(-7.715274834628325e-16, -4.2), 
        Coord(2.969848480983499, -2.9698484809835004)
    };
    Octagon o3(o2);
    o1 = std::move(o2);
    ASSERT_TRUE(o1 == o3);
}

TEST(oct_op_move, test02) {
    Octagon o1;
    Octagon o2 = {
        Coord(4.2, 0.0), Coord(2.9698484809835, 2.9698484809834995), Coord(2.571758278209442e-16, 4.2), 
        Coord(-2.9698484809834995, 2.9698484809835), Coord(-4.2, 5.143516556418884e-16), 
        Coord(-2.9698484809835004, -2.9698484809834995), Coord(-7.715274834628325e-16, -4.2), 
        Coord(2.969848480983499, -2.9698484809835004)
    };
    Octagon o3(o1);
    o2 = std::move(o1);
    ASSERT_TRUE(o3 == o2);
}

TEST(oct_op_move, test03) {
    Octagon o1 = {
        Coord(2.3, -0.9), Coord(1.777460325558382, -5.838477631085023), Coord(4.9, -9.7), 
        Coord(9.838477631085023, -10.222539674441617), Coord(13.7, -7.100000000000001), 
        Coord(14.222539674441618, -2.161522368914977), Coord(11.100000000000001, 1.6999999999999995), 
        Coord(6.161522368914978, 2.222539674441619)
    };
    Octagon o2 = {
        Coord(5.0, 0.0), Coord(9.596551211459378, 7.702943725152284), Coord(7.4, 16.4), 
        Coord(-0.30294372515228396, 20.996551211459376), Coord(-8.999999999999998, 18.8), 
        Coord(-13.59655121145938, 11.097056274847716), Coord(-11.400000000000002, 2.400000000000002), 
        Coord(-3.697056274847717, -2.1965512114593784)
    };
    Octagon o3(o2);
    o1 = std::move(o2);
    ASSERT_TRUE(o1 == o3);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
