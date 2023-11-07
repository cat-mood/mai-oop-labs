#include <gtest/gtest.h>
#include "coord.h"
#include "hexagon.h"
#include "octagon.h"
#include "triangle.h"
#include "array.h"
#include "figure.h"
#include <cmath>

/*------------------------HEX_GET_CENTER------------------------------------------------------------------*/

TEST(hex_get_center, test01) {
    Hexagon<int> h;
    ASSERT_TRUE(h.get_center() == Coord<int>(0, 0));
}

TEST(hex_get_center, test02) {
    Hexagon<double> h = {Coord<double>(0, 1), Coord<double>(-0.8660254037844386, 0.5), Coord<double>(-0.8660254037844386, -0.5), Coord<double>(0, -1),
    Coord<double>(0.8660254037844386, -0.5), Coord<double>(0.8660254037844386, 0.5)};
    ASSERT_TRUE(h.get_center() == Coord<double>(0, 0));
}

TEST(hex_get_center, test03) {
    Hexagon<double> h = {Coord<double>(0.8660254037844386, 0.5), Coord<double>(0, 1), Coord<double>(-0.8660254037844386, 0.5), Coord<double>(-0.8660254037844386, -0.5), Coord<double>(0, -1),
    Coord<double>(0.8660254037844386, -0.5)};
    ASSERT_TRUE(h.get_center() == Coord<double>(0, 0));
}

TEST(hex_get_center, test04) {
    Hexagon<double> h = {Coord<double>(123.0, 432.0), Coord<double>(-312.62297443487745, 322.52112466548596), 
    Coord<double>(-435.62297443487745, -109.47887533451406), Coord<double>(-123.0, -432.0), 
    Coord<double>(312.62297443487745, -322.52112466548596), Coord<double>(435.62297443487745, 109.47887533451406)};
    ASSERT_TRUE(h.get_center() == Coord<double>(0, 0));
}

TEST(hex_get_center, test05) {
    Hexagon<double> h = {Coord<double>(-0.848076211353316, 10.12916512459885), Coord<double>(-7.348076211353316, 7.129165124598851), Coord<double>(-8, 0),
    Coord<double>(-2.151923788646684, -4.129165124598851), Coord<double>(4.348076211353316, -1.1291651245988508), Coord<double>(5, 6)};
    ASSERT_TRUE(h.get_center() == Coord<double>(-1.5, 3));
}

/*------------------------------HEX_GET_AREA-----------------------------------------------------------------*/


TEST(hex_get_area, test01) {
    Hexagon<int> h;
    ASSERT_TRUE(is_eq((double) h, 0));
}

TEST(hex_get_area, test02) {
    Hexagon<double> h = {Coord<double>(0, 1), Coord<double>(-0.8660254037844386, 0.5), Coord<double>(-0.8660254037844386, -0.5), Coord<double>(0, -1),
    Coord<double>(0.8660254037844386, -0.5), Coord<double>(0.8660254037844386, 0.5)};
    ASSERT_TRUE(is_eq((double) h, 2.5980762113533156));
}

TEST(hex_get_area, test03) {
    Hexagon<double> h = {Coord<double>(-0.8660254037844386, -0.5), Coord<double>(0, -1), Coord<double>(0.8660254037844386, -0.5), 
    Coord<double>(0.8660254037844386, 0.5), Coord<double>(0, 1), Coord<double>(-0.8660254037844386, 0.5)};
    ASSERT_TRUE(is_eq((double) h, 2.5980762113533156));
}

TEST(hex_get_area, test04) {
    Hexagon<double> h = {Coord<double>(-243.5, -198.665), Coord<double>(-15.233731546200573, -290.2637746161375), Coord<double>(178.22626845379943, -138.3787746161375),
    Coord<double>(143.42000000000002, 105.10499999999999), Coord<double>(-84.84626845379944, 196.70377461613748), Coord<double>(-278.3062684537995, 44.81877461613749)};
    ASSERT_TRUE(is_eq((double) h, 157172.76336402984));
}

TEST(hex_get_area, test05) {
    Hexagon<double> h = {
        Coord<double>(7.0, 45.0), Coord<double>(-70.07883832488648, 112.50446416709055), Coord<double>(-167.07883832488648, 79.50446416709055), 
        Coord<double>(-187.0, -21.0), Coord<double>(-109.92116167511352, -88.50446416709055), 
        Coord<double>(-12.921161675113527, -55.504464167090546)
    };
    ASSERT_TRUE(is_eq((double) h, 27274.604066787113));
}

/*-----------------------------------HEX_EQ------------------------------------------------------------------------*/

TEST(hex_eq, test01) {
    Hexagon<double> h1 = {Coord<double>(0, 1), Coord<double>(-0.8660254037844386, 0.5), Coord<double>(-0.8660254037844386, -0.5), Coord<double>(0, -1),
    Coord<double>(0.8660254037844386, -0.5), Coord<double>(0.8660254037844386, 0.5)};
    Hexagon<double> h2 = {Coord<double>(-0.8660254037844386, -0.5), Coord<double>(0, -1), Coord<double>(0.8660254037844386, -0.5), 
    Coord<double>(0.8660254037844386, 0.5), Coord<double>(0, 1), Coord<double>(-0.8660254037844386, 0.5)};
    ASSERT_TRUE(h1 == h2);
}

TEST(hex_eq, test02) {
    Hexagon<float> h1, h2;
    ASSERT_TRUE(h1 == h2);
}

TEST(hex_eq, test03) {
    Hexagon<double> h1 = {Coord<double>(5, 0), Coord<double>(3, 3.4641016151377544), Coord<double>(-1, 3.4641016151377544), Coord<double>(-3, 0), 
    Coord<double>(-1, -3.4641016151377544), Coord<double>(3, -3.4641016151377544)};
    Hexagon<double> h2 = {Coord<double>(5, 2), Coord<double>(3, 5.464101615137754), Coord<double>(-1, 5.464101615137754), Coord<double>(-3, 2),
    Coord<double>(-1, -1.4641016151377544), Coord<double>(3, -1.4641016151377544)};
    ASSERT_TRUE(h1 == h2);
}

TEST(hex_eq, test04) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {Coord<double>(0, 2), Coord<double>(-1.7320508075688772, 1), Coord<double>(-1.7320508075688772, -1), Coord<double>(0, -2),
    Coord<double>(1.7320508075688772, -1), Coord<double>(1.7320508075688772, 1)};
    ASSERT_TRUE(h1 == h2);
}

/*------------------------------------HEX_NOT_EQ---------------------------------------------------------*/

TEST(hex_not_eq, test01) {
    Hexagon<double> h1 = {Coord<double>(0, 1), Coord<double>(-0.8660254037844386, 0.5), Coord<double>(-0.8660254037844386, -0.5), Coord<double>(0, -1),
    Coord<double>(0.8660254037844386, -0.5), Coord<double>(0.8660254037844386, 0.5)};
    Hexagon<double> h2 = {Coord<double>(-0.8660254037844386, -0.5), Coord<double>(0, -1), Coord<double>(0.8660254037844386, -0.5), 
    Coord<double>(0.8660254037844386, 0.5), Coord<double>(0, 1), Coord<double>(-0.8660254037844386, 0.5)};
    ASSERT_FALSE(h1 != h2);
}

TEST(hex_not_eq, test02) {
    Hexagon<int> h1, h2;
    ASSERT_FALSE(h1 != h2);
}

TEST(hex_not_eq, test03) {
    Hexagon<double> h1 = {Coord<double>(5, 0), Coord<double>(3, 3.4641016151377544), Coord<double>(-1, 3.4641016151377544), Coord<double>(-3, 0), 
    Coord<double>(-1, -3.4641016151377544), Coord<double>(3, -3.4641016151377544)};
    Hexagon<double> h2 = {Coord<double>(5, 2), Coord<double>(3, 5.464101615137754), Coord<double>(-1, 5.464101615137754), Coord<double>(-3, 2),
    Coord<double>(-1, -1.4641016151377544), Coord<double>(3, -1.4641016151377544)};
    ASSERT_FALSE(h1 != h2);
}

TEST(hex_not_eq, test04) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {
        Coord<double>(1.0, 7.0), Coord<double>(0.6339745962155614, 5.633974596215562), Coord<double>(1.6339745962155614, 4.633974596215562), 
        Coord<double>(3.0, 5.0), Coord<double>(3.3660254037844384, 6.366025403784438), Coord<double>(2.3660254037844384, 7.366025403784438)
    };
    ASSERT_TRUE(h1 != h2);
}

/*--------------------------------------------HEX_GREATER----------------------------------------------------------*/

TEST(hex_greater, test01) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {Coord<double>(5, 0), Coord<double>(2.5, 4.330127018922193), Coord<double>(-2.5, 4.330127018922193), Coord<double>(-5, 0),
    Coord<double>(-2.5, -4.330127018922193), Coord<double>(2.5, -4.330127018922193)};
    ASSERT_TRUE(h2 > h1);
}

TEST(hex_greater, test02) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {Coord<double>(100, 25), Coord<double>(35.17949192431123, 97.27241335952166), Coord<double>(-59.82050807568877, 77.27241335952166),
    Coord<double>(-90, -15), Coord<double>(-25.17949192431123, -87.27241335952166), Coord<double>(69.82050807568876, -67.27241335952166)};
    ASSERT_TRUE(h2 > h1);
}

TEST(hex_greater, test03) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {Coord<double>(0, 2), Coord<double>(-1.7320508075688772, 1), Coord<double>(-1.7320508075688772, -1), Coord<double>(0, -2),
    Coord<double>(1.7320508075688772, -1), Coord<double>(1.7320508075688772, 1)};
    ASSERT_FALSE(h2 > h1);
}

/*---------------------------------------HEX_GREATER_OR_NOT------------------------------------------------------------*/

TEST(hex_greater_or_eq, test01) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {Coord<double>(5, 0), Coord<double>(2.5, 4.330127018922193), Coord<double>(-2.5, 4.330127018922193), Coord<double>(-5, 0),
    Coord<double>(-2.5, -4.330127018922193), Coord<double>(2.5, -4.330127018922193)};
    ASSERT_TRUE(h2 >= h1);
}

TEST(hex_greater_or_eq, test02) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {Coord<double>(100, 25), Coord<double>(35.17949192431123, 97.27241335952166), Coord<double>(-59.82050807568877, 77.27241335952166),
    Coord<double>(-90, -15), Coord<double>(-25.17949192431123, -87.27241335952166), Coord<double>(69.82050807568876, -67.27241335952166)};
    ASSERT_TRUE(h2 >= h1);
}

TEST(hex_greater_or_eq, test03) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {Coord<double>(0, 2), Coord<double>(-1.7320508075688772, 1), Coord<double>(-1.7320508075688772, -1), Coord<double>(0, -2),
    Coord<double>(1.7320508075688772, -1), Coord<double>(1.7320508075688772, 1)};
    ASSERT_TRUE(h2 >= h1);
}

/*------------------------------------------HEX_LESS----------------------------------------------------------*/

TEST(hex_less, test01) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {Coord<double>(5, 0), Coord<double>(2.5, 4.330127018922193), Coord<double>(-2.5, 4.330127018922193), Coord<double>(-5, 0),
    Coord<double>(-2.5, -4.330127018922193), Coord<double>(2.5, -4.330127018922193)};
    ASSERT_FALSE(h2 < h1);
}

TEST(hex_less, test02) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {Coord<double>(100, 25), Coord<double>(35.17949192431123, 97.27241335952166), Coord<double>(-59.82050807568877, 77.27241335952166),
    Coord<double>(-90, -15), Coord<double>(-25.17949192431123, -87.27241335952166), Coord<double>(69.82050807568876, -67.27241335952166)};
    ASSERT_FALSE(h2 < h1);
}

TEST(hex_less, test03) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {Coord<double>(0, 2), Coord<double>(-1.7320508075688772, 1), Coord<double>(-1.7320508075688772, -1), Coord<double>(0, -2),
    Coord<double>(1.7320508075688772, -1), Coord<double>(1.7320508075688772, 1)};
    ASSERT_FALSE(h2 < h1);
}

/*-----------------------------------------HEX_LESS_OR_EQ----------------------------------------------------*/

TEST(hex_less_or_eq, test01) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {Coord<double>(5, 0), Coord<double>(2.5, 4.330127018922193), Coord<double>(-2.5, 4.330127018922193), Coord<double>(-5, 0),
    Coord<double>(-2.5, -4.330127018922193), Coord<double>(2.5, -4.330127018922193)};
    ASSERT_FALSE(h2 <= h1);
}

TEST(hex_less_or_eq, test02) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {Coord<double>(100, 25), Coord<double>(35.17949192431123, 97.27241335952166), Coord<double>(-59.82050807568877, 77.27241335952166),
    Coord<double>(-90, -15), Coord<double>(-25.17949192431123, -87.27241335952166), Coord<double>(69.82050807568876, -67.27241335952166)};
    ASSERT_FALSE(h2 <= h1);
}

TEST(hex_less_or_eq, test03) {
    Hexagon<double> h1 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h2 = {Coord<double>(0, 2), Coord<double>(-1.7320508075688772, 1), Coord<double>(-1.7320508075688772, -1), Coord<double>(0, -2),
    Coord<double>(1.7320508075688772, -1), Coord<double>(1.7320508075688772, 1)};
    ASSERT_TRUE(h2 <= h1);
}

/*---------------------------------HEX_OP_COPY--------------------------------------------------------------------*/

TEST(hex_op_copy, test01) {
    Hexagon<double> h1;
    Hexagon<double> h2 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    h1 = h2;
    ASSERT_TRUE(h1 == h2);
}

TEST(hex_op_copy, test02) {
    Hexagon<double> h1;
    Hexagon<double> h2 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    h2 = h1;
    ASSERT_TRUE(h1 == h2);
}

TEST(hex_op_copy, test03) {
    Hexagon<double> h1 = {Coord<double>(100, 25), Coord<double>(35.17949192431123, 97.27241335952166), Coord<double>(-59.82050807568877, 77.27241335952166),
    Coord<double>(-90, -15), Coord<double>(-25.17949192431123, -87.27241335952166), Coord<double>(69.82050807568876, -67.27241335952166)};
    Hexagon<double> h2(Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772));
    h1 = h2;
    ASSERT_TRUE(h1 == h2);
}

/*--------------------------------------HEX_OP_MOVE--------------------------------------------------------------*/

TEST(hex_op_move, test01) {
    Hexagon<double> h1;
    Hexagon<double> h2 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    Hexagon<double> h3(h2);
    h1 = std::move(h2);
    ASSERT_TRUE(h1 == h3);
}

TEST(hex_op_move, test02) {
    Hexagon<double> h1;
    Hexagon<double> h2 = {Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)};
    h2 = std::move(h1);
    ASSERT_TRUE(h2 == Hexagon<double>());
}

TEST(hex_op_move, test03) {
    Hexagon<double> h1 = {Coord<double>(100, 25), Coord<double>(35.17949192431123, 97.27241335952166), Coord<double>(-59.82050807568877, 77.27241335952166),
    Coord<double>(-90, -15), Coord<double>(-25.17949192431123, -87.27241335952166), Coord<double>(69.82050807568876, -67.27241335952166)};
    Hexagon<double> h2(Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
    Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772));
    Hexagon<double> h3(h2);
    h1 = std::move(h2);
    ASSERT_TRUE(h1 == h3);
}

/*--------------------------------------OCT_GET_CENTER-------------------------------------------------------------*/

TEST(oct_get_center, test01) {
    Octagon<int> o;
    ASSERT_TRUE(o.get_center() == Coord<int>(0, 0));
}

TEST(oct_get_center, test02) {
    Octagon<double> o = {Coord<double>(0, 2), Coord<double>(-1.414213562373095, 1.4142135623730951), Coord<double>(-2, 1.2246467991473532e-16), 
    Coord<double>(-1.4142135623730951, -1.414213562373095), Coord<double>(-2.4492935982947064e-16, -2), Coord<double>(1.414213562373095, -1.4142135623730954),
    Coord<double>(2, -3.6739403974420594e-16), Coord<double>(1.4142135623730954, 1.4142135623730947)};
    ASSERT_TRUE(o.get_center() == Coord<double>(0, 0));
}

TEST(oct_get_center, test03) {
    Octagon<double> o = {Coord<double>(-1.414213562373095, 1.4142135623730951), Coord<double>(-2, 1.2246467991473532e-16), 
    Coord<double>(-1.4142135623730951, -1.414213562373095), Coord<double>(-2.4492935982947064e-16, -2), Coord<double>(1.414213562373095, -1.4142135623730954),
    Coord<double>(2, -3.6739403974420594e-16), Coord<double>(1.4142135623730954, 1.4142135623730947), Coord<double>(0, 2)};
    ASSERT_TRUE(o.get_center() == Coord<double>(0, 0));
}

TEST(oct_get_center, test04) {
    Octagon<double> o = {
        Coord<double>(-46.0, 175.0), Coord<double>(-156.270598642227, 91.21677477306463), 
        Coord<double>(-175.0, -45.999999999999986), Coord<double>(-91.21677477306463, -156.270598642227), 
        Coord<double>(45.99999999999998, -175.0), Coord<double>(156.27059864222701, -91.21677477306466), 
        Coord<double>(175.0, 45.999999999999964), Coord<double>(91.21677477306467, 156.270598642227)
    };
    ASSERT_TRUE(o.get_center() == Coord<double>(0, 0));
}

TEST(oct_get_center, test05) {
    Octagon<double> o = {
        Coord<double>(-566.0, 23.0), Coord<double>(-470.9747468305833, -426.41125496954277), 
        Coord<double>(-86.00000000000003, -677.0), Coord<double>(363.41125496954277, -581.9747468305833), 
        Coord<double>(614.0, -197.00000000000006), Coord<double>(518.9747468305833, 252.41125496954277), 
        Coord<double>(134.0000000000001, 503.0), Coord<double>(-315.4112549695427, 407.9747468305833)
    };
    ASSERT_TRUE(o.get_center() == Coord<double>(24, -87));
}

/*-----------------------------------OCT_GET_AREA-------------------------------------------------------------------*/

TEST(oct_get_area, test01) {
    Octagon<float> o;
    ASSERT_TRUE(is_eq((double) o, 0));
}

TEST(oct_get_area, test02) {
    Octagon<double> o = {
        Coord<double>(10.0, -10.0), Coord<double>(14.142135623730951, -8.881784197001252e-16), Coord<double>(10.0, 10.0), 
        Coord<double>(8.881784197001252e-16, 14.142135623730951), Coord<double>(-9.999999999999998, 10.000000000000002), 
        Coord<double>(-14.142135623730951, 2.6645352591003757e-15), Coord<double>(-10.000000000000002, -9.999999999999998), 
        Coord<double>(-3.552713678800501e-15, -14.142135623730951)
    };
    ASSERT_TRUE(is_eq((double) o, 565.685424949238));
}

TEST(oct_get_area, test03) {
    Octagon<double> o = {
        Coord<double>(14.142135623730951, -8.881784197001252e-16), Coord<double>(10.0, 10.0), 
        Coord<double>(8.881784197001252e-16, 14.142135623730951), Coord<double>(-9.999999999999998, 10.000000000000002), 
        Coord<double>(-14.142135623730951, 2.6645352591003757e-15), Coord<double>(-10.000000000000002, -9.999999999999998), 
        Coord<double>(-3.552713678800501e-15, -14.142135623730951), Coord<double>(10.0, -10.0)
    };
    ASSERT_TRUE(is_eq((double) o, 565.685424949238));
}

TEST(oct_get_area, test04) {
    Octagon<double> o = {
        Coord<double>(1.0, 2.0), Coord<double>(-0.7071067811865474, 2.121320343559643), Coord<double>(-2.0, 1.0000000000000002), 
        Coord<double>(-2.121320343559643, -0.7071067811865474), Coord<double>(-1.0000000000000002, -1.9999999999999998), 
        Coord<double>(0.7071067811865472, -2.121320343559643), Coord<double>(1.9999999999999998, -1.0000000000000004), 
        Coord<double>(2.121320343559643, 0.707106781186547)
    };
    ASSERT_TRUE(is_eq((double) o, 14.142135623730951));
}

TEST(oct_get_area, test05) {
    Octagon<double> o = {
        Coord<double>(17.0, -69.0), Coord<double>(122.10764773832473, -4.75230867899738), Coord<double>(151.0, 114.99999999999999), 
        Coord<double>(86.75230867899738, 220.10764773832472), Coord<double>(-32.99999999999998, 249.0), 
        Coord<double>(-138.10764773832474, 184.7523086789974), Coord<double>(-167.0, 65.00000000000003), 
        Coord<double>(-102.7523086789974, -40.107647738324715)
    };
    ASSERT_TRUE(is_eq((double) o, 73273.2330936748));
}

/*---------------------------------------OCT_EQ--------------------------------------------------------------------*/

TEST(oct_eq, test01) {
    Octagon<double> o1 = {
        Coord<double>(4.0, -2.0), Coord<double>(4.242640687119286, 1.4142135623730947), Coord<double>(2.0000000000000004, 4.0), 
        Coord<double>(-1.4142135623730947, 4.242640687119286), Coord<double>(-3.9999999999999996, 2.0000000000000004), 
        Coord<double>(-4.242640687119286, -1.4142135623730945), Coord<double>(-2.000000000000001, -3.9999999999999996), 
        Coord<double>(1.414213562373094, -4.242640687119286)
    };
    Octagon<double> o2 = {
        Coord<double>(4.242640687119286, 1.4142135623730947), Coord<double>(2.0000000000000004, 4.0), 
        Coord<double>(-1.4142135623730947, 4.242640687119286), Coord<double>(-3.9999999999999996, 2.0000000000000004), 
        Coord<double>(-4.242640687119286, -1.4142135623730945), Coord<double>(-2.000000000000001, -3.9999999999999996), 
        Coord<double>(1.414213562373094, -4.242640687119286), Coord<double>(4.0, -2.0)
    };
    ASSERT_TRUE(o1 == o2);
}

TEST(oct_eq, test02) {
    Octagon<int> o1, o2;
    ASSERT_TRUE(o1 == o2);
}

TEST(oct_eq, test03) {
    Octagon<double> o1 = {
        Coord<double>(1.0, -2.0), Coord<double>(7.414213562373094, -3.48528137423857), Coord<double>(13.0, -4.286263797015736e-16), 
        Coord<double>(14.485281374238571, 6.414213562373094), Coord<double>(11.0, 12.0), Coord<double>(4.585786437626906, 13.485281374238571), 
        Coord<double>(-0.9999999999999991, 10.000000000000002), Coord<double>(-2.4852813742385704, 3.585786437626906)
    };
    Octagon<double> o2 = {
        Coord<double>(-2.0, -5.0), Coord<double>(4.414213562373094, -6.4852813742385695), Coord<double>(10.0, -3.0000000000000004), 
        Coord<double>(11.485281374238571, 3.414213562373094), Coord<double>(8.0, 9.0), Coord<double>(1.5857864376269069, 10.485281374238571), 
        Coord<double>(-3.999999999999999, 7.000000000000001), Coord<double>(-5.48528137423857, 0.5857864376269069)
    };
    ASSERT_TRUE(o1 == o2);
}

TEST(oct_eq, test04) {
    Octagon<double> o1 = {
        Coord<double>(2.0, 0.0), Coord<double>(1.4142135623730951, 1.414213562373095), Coord<double>(1.2246467991473532e-16, 2.0), 
        Coord<double>(-1.414213562373095, 1.4142135623730951), Coord<double>(-2.0, 2.4492935982947064e-16), 
        Coord<double>(-1.4142135623730954, -1.414213562373095), Coord<double>(-3.6739403974420594e-16, -2.0), 
        Coord<double>(1.4142135623730947, -1.4142135623730954)
    };
    Octagon<double> o2 = {
        Coord<double>(0.0, 2.0), Coord<double>(-1.414213562373095, 1.4142135623730951), Coord<double>(-2.0, 1.2246467991473532e-16), 
        Coord<double>(-1.4142135623730951, -1.414213562373095), Coord<double>(-2.4492935982947064e-16, -2.0), 
        Coord<double>(1.414213562373095, -1.4142135623730954), Coord<double>(2.0, -3.6739403974420594e-16), 
        Coord<double>(1.4142135623730954, 1.4142135623730947)
    };
    ASSERT_TRUE(o1 == o2);
}

/*-------------------------------------OCT_NOT_EQ------------------------------------------------------------*/

TEST(oct_not_eq, test01) {
    Octagon<double> o1 = {
        Coord<double>(4.0, -2.0), Coord<double>(4.242640687119286, 1.4142135623730947), Coord<double>(2.0000000000000004, 4.0), 
        Coord<double>(-1.4142135623730947, 4.242640687119286), Coord<double>(-3.9999999999999996, 2.0000000000000004), 
        Coord<double>(-4.242640687119286, -1.4142135623730945), Coord<double>(-2.000000000000001, -3.9999999999999996), 
        Coord<double>(1.414213562373094, -4.242640687119286)
    };
    Octagon<double> o2 = {
        Coord<double>(4.242640687119286, 1.4142135623730947), Coord<double>(2.0000000000000004, 4.0), 
        Coord<double>(-1.4142135623730947, 4.242640687119286), Coord<double>(-3.9999999999999996, 2.0000000000000004), 
        Coord<double>(-4.242640687119286, -1.4142135623730945), Coord<double>(-2.000000000000001, -3.9999999999999996), 
        Coord<double>(1.414213562373094, -4.242640687119286), Coord<double>(4.0, -2.0)
    };
    ASSERT_FALSE(o1 != o2);
}

TEST(oct_not_eq, test02) {
    Octagon<double> o1, o2 = {
        Coord<double>(4.242640687119286, 1.4142135623730947), Coord<double>(2.0000000000000004, 4.0), 
        Coord<double>(-1.4142135623730947, 4.242640687119286), Coord<double>(-3.9999999999999996, 2.0000000000000004), 
        Coord<double>(-4.242640687119286, -1.4142135623730945), Coord<double>(-2.000000000000001, -3.9999999999999996), 
        Coord<double>(1.414213562373094, -4.242640687119286), Coord<double>(4.0, -2.0)
    };
    ASSERT_TRUE(o1 != o2);
}

TEST(oct_not_eq, test03) {
    Octagon<double> o1 = {
        Coord<double>(1.0, -2.0), Coord<double>(7.414213562373094, -3.48528137423857), Coord<double>(13.0, -4.286263797015736e-16), 
        Coord<double>(14.485281374238571, 6.414213562373094), Coord<double>(11.0, 12.0), Coord<double>(4.585786437626906, 13.485281374238571), 
        Coord<double>(-0.9999999999999991, 10.000000000000002), Coord<double>(-2.4852813742385704, 3.585786437626906)
    };
    Octagon<double> o2 = {
        Coord<double>(-2.0, -5.0), Coord<double>(4.414213562373094, -6.4852813742385695), Coord<double>(10.0, -3.0000000000000004), 
        Coord<double>(11.485281374238571, 3.414213562373094), Coord<double>(8.0, 9.0), Coord<double>(1.5857864376269069, 10.485281374238571), 
        Coord<double>(-3.999999999999999, 7.000000000000001), Coord<double>(-5.48528137423857, 0.5857864376269069)
    };
    ASSERT_FALSE(o1 != o2);
}

TEST(oct_not_eq, test04) {
    Octagon<double> o1 = {
        Coord<double>(9.8, -3.0), Coord<double>(8.945941546018393, 5.261879502661796), Coord<double>(2.500000000000001, 10.5), 
        Coord<double>(-5.761879502661796, 9.645941546018392), Coord<double>(-11.0, 3.2000000000000015), 
        Coord<double>(-10.145941546018392, -5.061879502661796), Coord<double>(-3.700000000000002, -10.3), 
        Coord<double>(4.561879502661796, -9.445941546018393)
    };
    Octagon<double> o2 = {
        Coord<double>(6.4, 0.888), Coord<double>(27.35341670061596, 16.525977223318037), Coord<double>(31.112000000000002, 42.4), 
        Coord<double>(15.474022776681966, 63.353416700615966), Coord<double>(-10.399999999999997, 67.112), 
        Coord<double>(-31.353416700615963, 51.47402277668197), Coord<double>(-35.112, 25.60000000000001), 
        Coord<double>(-19.47402277668197, 4.646583299384041)
    };
    ASSERT_TRUE(o1 != o2);
}


/*---------------------------------------------OCT_GREATER---------------------------------------------------------*/

TEST(oct_greater, test01) {
    Octagon<double> o1 = {
        Coord<double>(2.2, 0.0), Coord<double>(1.5556349186104048, 1.5556349186104046), Coord<double>(1.3471114790620887e-16, 2.2), 
        Coord<double>(-1.5556349186104046, 1.5556349186104048), Coord<double>(-2.2, 2.6942229581241775e-16), 
        Coord<double>(-1.555634918610405, -1.5556349186104046), Coord<double>(-4.0413344371862655e-16, -2.2), 
        Coord<double>(1.5556349186104044, -1.555634918610405)
    };
    Octagon<double> o2 = {
        Coord<double>(4.5, 0.0), Coord<double>(3.1819805153394642, 3.181980515339464), Coord<double>(2.755455298081545e-16, 4.5), 
        Coord<double>(-3.181980515339464, 3.1819805153394642), Coord<double>(-4.5, 5.51091059616309e-16), 
        Coord<double>(-3.1819805153394647, -3.181980515339464), Coord<double>(-8.266365894244633e-16, -4.5), 
        Coord<double>(3.181980515339463, -3.1819805153394647)
    };
    ASSERT_TRUE(o2 > o1);
}

TEST(oct_greater, test02) {
    Octagon<double> o1 = {
        Coord<double>(4.3, -2.2), Coord<double>(5.596194077712559, 1.0707106781186542), Coord<double>(4.2, 4.3), 
        Coord<double>(0.9292893218813458, 5.596194077712559), Coord<double>(-2.2999999999999994, 4.200000000000001), 
        Coord<double>(-3.596194077712559, 0.9292893218813458), Coord<double>(-2.2000000000000006, -2.2999999999999994), 
        Coord<double>(1.0707106781186537, -3.5961940777125587)
    };
    Octagon<double> o2 = {
        Coord<double>(900.0, 230.4), Coord<double>(473.40763287064686, 793.4850783285272), Coord<double>(-226.39999999999995, 890.0), 
        Coord<double>(-789.4850783285272, 463.40763287064686), Coord<double>(-886.0, -236.3999999999999), 
        Coord<double>(-459.40763287064686, -799.4850783285272), Coord<double>(240.39999999999984, -896.0), 
        Coord<double>(803.485078328527, -469.4076328706469)
    };
    ASSERT_TRUE(o2 > o1);
}

TEST(oct_greater, test03) {
    Octagon<double> o1 = {
        Coord<double>(4.2, 0.0), Coord<double>(2.9698484809835, 2.9698484809834995), Coord<double>(2.571758278209442e-16, 4.2), 
        Coord<double>(-2.9698484809834995, 2.9698484809835), Coord<double>(-4.2, 5.143516556418884e-16), 
        Coord<double>(-2.9698484809835004, -2.9698484809834995), Coord<double>(-7.715274834628325e-16, -4.2), 
        Coord<double>(2.969848480983499, -2.9698484809835004)
    };
    Octagon<double> o2 = {
        Coord<double>(0.0, 4.2), Coord<double>(-2.9698484809834995, 2.9698484809835), Coord<double>(-4.2, 2.571758278209442e-16), 
        Coord<double>(-2.9698484809835, -2.9698484809834995), Coord<double>(-5.143516556418884e-16, -4.2), 
        Coord<double>(2.9698484809834995, -2.9698484809835004), Coord<double>(4.2, -7.715274834628325e-16), 
        Coord<double>(2.9698484809835004, 2.969848480983499)
    };
    ASSERT_FALSE(o2 > o1);
}

/*-------------------------------------------OCT_GREATER_OR_EQ--------------------------------------------------*/

TEST(oct_greater_or_eq, test01) {
    Octagon<double> o1 = {
        Coord<double>(2.2, 0.0), Coord<double>(1.5556349186104048, 1.5556349186104046), Coord<double>(1.3471114790620887e-16, 2.2), 
        Coord<double>(-1.5556349186104046, 1.5556349186104048), Coord<double>(-2.2, 2.6942229581241775e-16), 
        Coord<double>(-1.555634918610405, -1.5556349186104046), Coord<double>(-4.0413344371862655e-16, -2.2), 
        Coord<double>(1.5556349186104044, -1.555634918610405)
    };
    Octagon<double> o2 = {
        Coord<double>(4.5, 0.0), Coord<double>(3.1819805153394642, 3.181980515339464), Coord<double>(2.755455298081545e-16, 4.5), 
        Coord<double>(-3.181980515339464, 3.1819805153394642), Coord<double>(-4.5, 5.51091059616309e-16), 
        Coord<double>(-3.1819805153394647, -3.181980515339464), Coord<double>(-8.266365894244633e-16, -4.5), 
        Coord<double>(3.181980515339463, -3.1819805153394647)
    };
    ASSERT_TRUE(o2 >= o1);
}

TEST(oct_greater_or_eq, test02) {
    Octagon<double> o1 = {
        Coord<double>(4.3, -2.2), Coord<double>(5.596194077712559, 1.0707106781186542), Coord<double>(4.2, 4.3), 
        Coord<double>(0.9292893218813458, 5.596194077712559), Coord<double>(-2.2999999999999994, 4.200000000000001), 
        Coord<double>(-3.596194077712559, 0.9292893218813458), Coord<double>(-2.2000000000000006, -2.2999999999999994), 
        Coord<double>(1.0707106781186537, -3.5961940777125587)
    };
    Octagon<double> o2 = {
        Coord<double>(900.0, 230.4), Coord<double>(473.40763287064686, 793.4850783285272), Coord<double>(-226.39999999999995, 890.0), 
        Coord<double>(-789.4850783285272, 463.40763287064686), Coord<double>(-886.0, -236.3999999999999), 
        Coord<double>(-459.40763287064686, -799.4850783285272), Coord<double>(240.39999999999984, -896.0), 
        Coord<double>(803.485078328527, -469.4076328706469)
    };
    ASSERT_TRUE(o2 >= o1);
}

TEST(oct_greater_or_eq, test03) {
    Octagon<double> o1 = {
        Coord<double>(4.2, 0.0), Coord<double>(2.9698484809835, 2.9698484809834995), Coord<double>(2.571758278209442e-16, 4.2), 
        Coord<double>(-2.9698484809834995, 2.9698484809835), Coord<double>(-4.2, 5.143516556418884e-16), 
        Coord<double>(-2.9698484809835004, -2.9698484809834995), Coord<double>(-7.715274834628325e-16, -4.2), 
        Coord<double>(2.969848480983499, -2.9698484809835004)
    };
    Octagon<double> o2 = {
        Coord<double>(0.0, 4.2), Coord<double>(-2.9698484809834995, 2.9698484809835), Coord<double>(-4.2, 2.571758278209442e-16), 
        Coord<double>(-2.9698484809835, -2.9698484809834995), Coord<double>(-5.143516556418884e-16, -4.2), 
        Coord<double>(2.9698484809834995, -2.9698484809835004), Coord<double>(4.2, -7.715274834628325e-16), 
        Coord<double>(2.9698484809835004, 2.969848480983499)
    };
    ASSERT_TRUE(o2 >= o1);
}

/*-------------------------------------------OCT_LESS-------------------------------------------------------*/

TEST(oct_less, test01) {
    Octagon<double> o1 = {
        Coord<double>(2.2, 0.0), Coord<double>(1.5556349186104048, 1.5556349186104046), Coord<double>(1.3471114790620887e-16, 2.2), 
        Coord<double>(-1.5556349186104046, 1.5556349186104048), Coord<double>(-2.2, 2.6942229581241775e-16), 
        Coord<double>(-1.555634918610405, -1.5556349186104046), Coord<double>(-4.0413344371862655e-16, -2.2), 
        Coord<double>(1.5556349186104044, -1.555634918610405)
    };
    Octagon<double> o2 = {
        Coord<double>(4.5, 0.0), Coord<double>(3.1819805153394642, 3.181980515339464), Coord<double>(2.755455298081545e-16, 4.5), 
        Coord<double>(-3.181980515339464, 3.1819805153394642), Coord<double>(-4.5, 5.51091059616309e-16), 
        Coord<double>(-3.1819805153394647, -3.181980515339464), Coord<double>(-8.266365894244633e-16, -4.5), 
        Coord<double>(3.181980515339463, -3.1819805153394647)
    };
    ASSERT_TRUE(o1 < o2);
}

TEST(oct_less, test02) {
    Octagon<double> o1 = {
        Coord<double>(4.3, -2.2), Coord<double>(5.596194077712559, 1.0707106781186542), Coord<double>(4.2, 4.3), 
        Coord<double>(0.9292893218813458, 5.596194077712559), Coord<double>(-2.2999999999999994, 4.200000000000001), 
        Coord<double>(-3.596194077712559, 0.9292893218813458), Coord<double>(-2.2000000000000006, -2.2999999999999994), 
        Coord<double>(1.0707106781186537, -3.5961940777125587)
    };
    Octagon<double> o2 = {
        Coord<double>(900.0, 230.4), Coord<double>(473.40763287064686, 793.4850783285272), Coord<double>(-226.39999999999995, 890.0), 
        Coord<double>(-789.4850783285272, 463.40763287064686), Coord<double>(-886.0, -236.3999999999999), 
        Coord<double>(-459.40763287064686, -799.4850783285272), Coord<double>(240.39999999999984, -896.0), 
        Coord<double>(803.485078328527, -469.4076328706469)
    };
    ASSERT_TRUE(o1 < o2);
}

TEST(oct_less, test03) {
    Octagon<double> o1 = {
        Coord<double>(4.2, 0.0), Coord<double>(2.9698484809835, 2.9698484809834995), Coord<double>(2.571758278209442e-16, 4.2), 
        Coord<double>(-2.9698484809834995, 2.9698484809835), Coord<double>(-4.2, 5.143516556418884e-16), 
        Coord<double>(-2.9698484809835004, -2.9698484809834995), Coord<double>(-7.715274834628325e-16, -4.2), 
        Coord<double>(2.969848480983499, -2.9698484809835004)
    };
    Octagon<double> o2 = {
        Coord<double>(0.0, 4.2), Coord<double>(-2.9698484809834995, 2.9698484809835), Coord<double>(-4.2, 2.571758278209442e-16), 
        Coord<double>(-2.9698484809835, -2.9698484809834995), Coord<double>(-5.143516556418884e-16, -4.2), 
        Coord<double>(2.9698484809834995, -2.9698484809835004), Coord<double>(4.2, -7.715274834628325e-16), 
        Coord<double>(2.9698484809835004, 2.969848480983499)
    };
    ASSERT_FALSE(o1 < o2);
}

/*----------------------------------------OCT_LESS_OR_EQ---------------------------------------------------------*/

TEST(oct_less_or_eq, test01) {
    Octagon<double> o1 = {
        Coord<double>(2.2, 0.0), Coord<double>(1.5556349186104048, 1.5556349186104046), Coord<double>(1.3471114790620887e-16, 2.2), 
        Coord<double>(-1.5556349186104046, 1.5556349186104048), Coord<double>(-2.2, 2.6942229581241775e-16), 
        Coord<double>(-1.555634918610405, -1.5556349186104046), Coord<double>(-4.0413344371862655e-16, -2.2), 
        Coord<double>(1.5556349186104044, -1.555634918610405)
    };
    Octagon<double> o2 = {
        Coord<double>(4.5, 0.0), Coord<double>(3.1819805153394642, 3.181980515339464), Coord<double>(2.755455298081545e-16, 4.5), 
        Coord<double>(-3.181980515339464, 3.1819805153394642), Coord<double>(-4.5, 5.51091059616309e-16), 
        Coord<double>(-3.1819805153394647, -3.181980515339464), Coord<double>(-8.266365894244633e-16, -4.5), 
        Coord<double>(3.181980515339463, -3.1819805153394647)
    };
    ASSERT_TRUE(o1 <= o2);
}

TEST(oct_less_or_eq, test02) {
    Octagon<double> o1 = {
        Coord<double>(4.3, -2.2), Coord<double>(5.596194077712559, 1.0707106781186542), Coord<double>(4.2, 4.3), 
        Coord<double>(0.9292893218813458, 5.596194077712559), Coord<double>(-2.2999999999999994, 4.200000000000001), 
        Coord<double>(-3.596194077712559, 0.9292893218813458), Coord<double>(-2.2000000000000006, -2.2999999999999994), 
        Coord<double>(1.0707106781186537, -3.5961940777125587)
    };
    Octagon<double> o2 = {
        Coord<double>(900.0, 230.4), Coord<double>(473.40763287064686, 793.4850783285272), Coord<double>(-226.39999999999995, 890.0), 
        Coord<double>(-789.4850783285272, 463.40763287064686), Coord<double>(-886.0, -236.3999999999999), 
        Coord<double>(-459.40763287064686, -799.4850783285272), Coord<double>(240.39999999999984, -896.0), 
        Coord<double>(803.485078328527, -469.4076328706469)
    };
    ASSERT_TRUE(o1 <= o2);
}

TEST(oct_less_or_eq, test03) {
    Octagon<double> o1 = {
        Coord<double>(4.2, 0.0), Coord<double>(2.9698484809835, 2.9698484809834995), Coord<double>(2.571758278209442e-16, 4.2), 
        Coord<double>(-2.9698484809834995, 2.9698484809835), Coord<double>(-4.2, 5.143516556418884e-16), 
        Coord<double>(-2.9698484809835004, -2.9698484809834995), Coord<double>(-7.715274834628325e-16, -4.2), 
        Coord<double>(2.969848480983499, -2.9698484809835004)
    };
    Octagon<double> o2 = {
        Coord<double>(0.0, 4.2), Coord<double>(-2.9698484809834995, 2.9698484809835), Coord<double>(-4.2, 2.571758278209442e-16), 
        Coord<double>(-2.9698484809835, -2.9698484809834995), Coord<double>(-5.143516556418884e-16, -4.2), 
        Coord<double>(2.9698484809834995, -2.9698484809835004), Coord<double>(4.2, -7.715274834628325e-16), 
        Coord<double>(2.9698484809835004, 2.969848480983499)
    };
    ASSERT_TRUE(o1 <= o2);
}

/*--------------------------------------------OCT_OP_COPY--------------------------------------------------------*/

TEST(oct_op_copy, test01) {
    Octagon<double> o1;
    Octagon<double> o2 = {
        Coord<double>(4.2, 0.0), Coord<double>(2.9698484809835, 2.9698484809834995), Coord<double>(2.571758278209442e-16, 4.2), 
        Coord<double>(-2.9698484809834995, 2.9698484809835), Coord<double>(-4.2, 5.143516556418884e-16), 
        Coord<double>(-2.9698484809835004, -2.9698484809834995), Coord<double>(-7.715274834628325e-16, -4.2), 
        Coord<double>(2.969848480983499, -2.9698484809835004)
    };
    o1 = o2;
    ASSERT_TRUE(o1 == o2);
}

TEST(oct_op_copy, test02) {
    Octagon<double> o1;
    Octagon<double> o2 = {
        Coord<double>(4.2, 0.0), Coord<double>(2.9698484809835, 2.9698484809834995), Coord<double>(2.571758278209442e-16, 4.2), 
        Coord<double>(-2.9698484809834995, 2.9698484809835), Coord<double>(-4.2, 5.143516556418884e-16), 
        Coord<double>(-2.9698484809835004, -2.9698484809834995), Coord<double>(-7.715274834628325e-16, -4.2), 
        Coord<double>(2.969848480983499, -2.9698484809835004)
    };
    o2 = o1;
    ASSERT_TRUE(o1 == o2);
}

TEST(oct_op_copy, test03) {
    Octagon<double> o1 = {
        Coord<double>(2.3, -0.9), Coord<double>(1.777460325558382, -5.838477631085023), Coord<double>(4.9, -9.7), 
        Coord<double>(9.838477631085023, -10.222539674441617), Coord<double>(13.7, -7.100000000000001), 
        Coord<double>(14.222539674441618, -2.161522368914977), Coord<double>(11.100000000000001, 1.6999999999999995), 
        Coord<double>(6.161522368914978, 2.222539674441619)
    };
    Octagon<double> o2 = {
        Coord<double>(5.0, 0.0), Coord<double>(9.596551211459378, 7.702943725152284), Coord<double>(7.4, 16.4), 
        Coord<double>(-0.30294372515228396, 20.996551211459376), Coord<double>(-8.999999999999998, 18.8), 
        Coord<double>(-13.59655121145938, 11.097056274847716), Coord<double>(-11.400000000000002, 2.400000000000002), 
        Coord<double>(-3.697056274847717, -2.1965512114593784)
    };
    o1 = o2;
    ASSERT_TRUE(o1 == o2);
}

/*------------------------------------------OCT_OP_MOVE-----------------------------------------------------------*/

TEST(oct_op_move, test01) {
    Octagon<double> o1;
    Octagon<double> o2 = {
        Coord<double>(4.2, 0.0), Coord<double>(2.9698484809835, 2.9698484809834995), Coord<double>(2.571758278209442e-16, 4.2), 
        Coord<double>(-2.9698484809834995, 2.9698484809835), Coord<double>(-4.2, 5.143516556418884e-16), 
        Coord<double>(-2.9698484809835004, -2.9698484809834995), Coord<double>(-7.715274834628325e-16, -4.2), 
        Coord<double>(2.969848480983499, -2.9698484809835004)
    };
    Octagon<double> o3(o2);
    o1 = std::move(o2);
    ASSERT_TRUE(o1 == o3);
}

TEST(oct_op_move, test02) {
    Octagon<double> o1;
    Octagon<double> o2 = {
        Coord<double>(4.2, 0.0), Coord<double>(2.9698484809835, 2.9698484809834995), Coord<double>(2.571758278209442e-16, 4.2), 
        Coord<double>(-2.9698484809834995, 2.9698484809835), Coord<double>(-4.2, 5.143516556418884e-16), 
        Coord<double>(-2.9698484809835004, -2.9698484809834995), Coord<double>(-7.715274834628325e-16, -4.2), 
        Coord<double>(2.969848480983499, -2.9698484809835004)
    };
    Octagon<double> o3(o1);
    o2 = std::move(o1);
    ASSERT_TRUE(o3 == o2);
}

TEST(oct_op_move, test03) {
    Octagon<double> o1 = {
        Coord<double>(2.3, -0.9), Coord<double>(1.777460325558382, -5.838477631085023), Coord<double>(4.9, -9.7), 
        Coord<double>(9.838477631085023, -10.222539674441617), Coord<double>(13.7, -7.100000000000001), 
        Coord<double>(14.222539674441618, -2.161522368914977), Coord<double>(11.100000000000001, 1.6999999999999995), 
        Coord<double>(6.161522368914978, 2.222539674441619)
    };
    Octagon<double> o2 = {
        Coord<double>(5.0, 0.0), Coord<double>(9.596551211459378, 7.702943725152284), Coord<double>(7.4, 16.4), 
        Coord<double>(-0.30294372515228396, 20.996551211459376), Coord<double>(-8.999999999999998, 18.8), 
        Coord<double>(-13.59655121145938, 11.097056274847716), Coord<double>(-11.400000000000002, 2.400000000000002), 
        Coord<double>(-3.697056274847717, -2.1965512114593784)
    };
    Octagon<double> o3(o2);
    o1 = std::move(o2);
    ASSERT_TRUE(o1 == o3);
}

/*----------------------------------------TRI_GET_CENTER-----------------------------------------------------------*/

TEST(tri_get_center, test01) {
    Triangle<int> t;
    ASSERT_TRUE(t.get_center() == Coord<int>(0, 0));
}

TEST(tri_get_center, test02) {
    Triangle<double> t = {
        Coord<double>(0.0, 2.0), Coord<double>(-1.7320508075688774, -0.9999999999999996), Coord<double>(1.7320508075688767, -1.0000000000000009)
    };
    ASSERT_TRUE(t.get_center() == Coord<double>(0, 0));
}

TEST(tri_get_center, test03) {
    Triangle<double> t = {
        Coord<double>(-1.7320508075688774, -0.9999999999999996), Coord<double>(1.7320508075688767, -1.0000000000000009), Coord<double>(0.0, 2.0)
    };
    ASSERT_TRUE(t.get_center() == Coord<double>(0, 0));
}

TEST(tri_get_center, test04) {
    Triangle<double> t = {
        Coord<double>(4.3, -0.56), Coord<double>(-1.6650257738807133, 4.003909236273087), Coord<double>(-2.6349742261192874, -3.4439092362730848)
    };
    ASSERT_TRUE(t.get_center() == Coord<double>(0, 0));
}

TEST(tri_get_center, test05) {
    Triangle<double> t = {
        Coord<double>(0.0, -4.6), Coord<double>(8.078460969082652, -4.464101615137755), Coord<double>(3.92153903091735, 2.4641016151377544)
    };
    ASSERT_TRUE(t.get_center() == Coord<double>(4, -2.2));
}

/*----------------------------------------------TRI_GET_AREA-------------------------------------------------------*/

TEST(tri_get_area, test01) {
    Triangle<float> t;
    ASSERT_TRUE(is_eq((double) t, 0));
}

TEST(tri_get_area, test02) {
    Triangle<double> t = {
        Coord<double>(0.4, 2.2), Coord<double>(0.26076951545867333, -0.11961524227066311), Coord<double>(2.3392304845413268, 0.9196152422706624)
    };
    ASSERT_TRUE(is_eq((double) t, 2.338268590217985));
}

TEST(tri_get_area, test03) {
    Triangle<double> t = {
        Coord<double>(0.26076951545867333, -0.11961524227066311), Coord<double>(2.3392304845413268, 0.9196152422706624), Coord<double>(0.4, 2.2)
    };
    ASSERT_TRUE(is_eq((double) t, 2.338268590217985));
}

TEST(tri_get_area, test04) {
    Triangle<double> t = {
        Coord<double>(-23.4, 98.0), Coord<double>(-70.80446416709057, -68.63101985234027), Coord<double>(97.20446416709052, -26.368980147659748)
    };
    ASSERT_TRUE(is_eq((double) t, 12996.04486290733));
}

TEST(tri_get_area, test05) {
    Triangle<double> t = {
        Coord<double>(0.123789, -9.542), Coord<double>(2.3720981337110754, 15.106758116430415), Coord<double>(-20.098507133711074, 4.729471883569589)
    };
    ASSERT_TRUE(is_eq((double) t, 265.2705832730003));
}

/*-----------------------------------------TRI_EQ-------------------------------------------------------------------*/

TEST(tri_eq, test01) {
    Triangle<double> t1 = {
        Coord<double>(65.3, 1.23), Coord<double>(-34.941748427090815, 45.84460043841964), Coord<double>(-23.4582515729092, -63.27460043841962)
    };
    Triangle<double> t2 = {
        Coord<double>(-34.941748427090815, 45.84460043841964), Coord<double>(-23.4582515729092, -63.27460043841962), Coord<double>(65.3, 1.23)
    };
    ASSERT_TRUE(t1 == t2);
}

TEST(tri_eq, test02) {
    Triangle<int> t1, t2;
    ASSERT_TRUE(t1 == t2);
}

TEST(tri_eq, test03) {
    Triangle<double> t1 = {
        Coord<double>(5.0, -4.0), Coord<double>(0.9641016151377557, 6.330127018922193), Coord<double>(-5.964101615137755, -2.33012701892219)
    };
    Triangle<double> t2 = {
        Coord<double>(6.0, -6.0), Coord<double>(1.9641016151377557, 4.330127018922193), Coord<double>(-4.964101615137755, -4.33012701892219)
    };
    ASSERT_TRUE(t1 == t2);
}

TEST(tri_eq, test04) {
    Triangle<double> t1 = {
        Coord<double>(0.0, 5.0), Coord<double>(-4.330127018922194, -2.499999999999999), Coord<double>(4.330127018922192, -2.500000000000002)
    };
    Triangle<double> t2 = {
        Coord<double>(5.0, 0.0), Coord<double>(-2.499999999999999, 4.330127018922194), Coord<double>(-2.500000000000002, -4.330127018922192)
    };
    ASSERT_TRUE(t1 == t2);
}

/*-------------------------------------------TRI_NOT_EQ--------------------------------------------------------*/

TEST(tri_not_eq, test01) {
    Triangle<double> t1 = {
        Coord<double>(65.3, 1.23), Coord<double>(-34.941748427090815, 45.84460043841964), Coord<double>(-23.4582515729092, -63.27460043841962)
    };
    Triangle<double> t2 = {
        Coord<double>(-34.941748427090815, 45.84460043841964), Coord<double>(-23.4582515729092, -63.27460043841962), Coord<double>(65.3, 1.23)
    };
    ASSERT_FALSE(t1 != t2);
}

TEST(tri_not_eq, test02) {
    Triangle<double> t1, t2 = {
        Coord<double>(5.0, 0.0), Coord<double>(-2.499999999999999, 4.330127018922194), Coord<double>(-2.500000000000002, -4.330127018922192)
    };
    ASSERT_TRUE(t1 != t2);
}

TEST(tri_not_eq, test03) {
    Triangle<double> t1 = {
        Coord<double>(5.0, -4.0), Coord<double>(0.9641016151377557, 6.330127018922193), Coord<double>(-5.964101615137755, -2.33012701892219)
    };
    Triangle<double> t2 = {
        Coord<double>(6.0, -6.0), Coord<double>(1.9641016151377557, 4.330127018922193), Coord<double>(-4.964101615137755, -4.33012701892219)
    };
    ASSERT_FALSE(t1 != t2);
}

TEST(tri_not_eq, test04) {
    Triangle<double> t1 = {
        Coord<double>(-4.0, 2.0), Coord<double>(16.809807621135327, -9.414548031846808), Coord<double>(16.290192378864674, 14.314548031846806)
    };
    Triangle<double> t2 = {
        Coord<double>(1.6666, 34.2), Coord<double>(-70.04571706048444, -83.19687444091751), Coord<double>(67.47911706048441, -86.60312555908251)
    };
    ASSERT_TRUE(t1 != t2);
}

/*------------------------------------------------TRI_GREATER--------------------------------------------------------*/

TEST(tri_greater, test01) {
    Triangle<double> t1 = {
        Coord<double>(2.2, 0.0), Coord<double>(-1.0999999999999996, 1.9052558883257653), Coord<double>(-1.100000000000001, -1.9052558883257646)
    };
    Triangle<double> t2 = {
        Coord<double>(4.5, 0.0), Coord<double>(-2.249999999999999, 3.897114317029974), Coord<double>(-2.2500000000000018, -3.8971143170299727)
    };
    ASSERT_TRUE(t2 > t1);
}

TEST(tri_greater, test02) {
    Triangle<double> t1 = {
        Coord<double>(4.62, -0.2333234), Coord<double>(-0.07921730041284514, -3.4535822266260965), Coord<double>(5.059217300412844, -5.913094373373904)
    };
    Triangle<double> t2 = {
        Coord<double>(100.0, 213.0), Coord<double>(-244.0233206221807, -79.22004323127496), Coord<double>(181.0583206221806, -231.04295676872505)
    };
    ASSERT_TRUE(t2 > t1);
}

TEST(tri_greater, test03) {
    Triangle<double> t1 = {
        Coord<double>(0.0, 5.0), Coord<double>(-4.330127018922194, -2.499999999999999), Coord<double>(4.330127018922192, -2.500000000000002)
    };
    Triangle<double> t2 = {
        Coord<double>(5.0, 0.0), Coord<double>(-2.499999999999999, 4.330127018922194), Coord<double>(-2.500000000000002, -4.330127018922192)
    };
    ASSERT_FALSE(t2 > t1);
}

/*----------------------------------------TRI_GREATER_OR_EQ--------------------------------------------------------*/

TEST(tri_greater_or_eq, test01) {
    Triangle<double> t1 = {
        Coord<double>(2.2, 0.0), Coord<double>(-1.0999999999999996, 1.9052558883257653), Coord<double>(-1.100000000000001, -1.9052558883257646)
    };
    Triangle<double> t2 = {
        Coord<double>(4.5, 0.0), Coord<double>(-2.249999999999999, 3.897114317029974), Coord<double>(-2.2500000000000018, -3.8971143170299727)
    };
    ASSERT_TRUE(t2 >= t1);
}

TEST(tri_greater_or_eq, test02) {
    Triangle<double> t1 = {
        Coord<double>(4.62, -0.2333234), Coord<double>(-0.07921730041284514, -3.4535822266260965), Coord<double>(5.059217300412844, -5.913094373373904)
    };
    Triangle<double> t2 = {
        Coord<double>(100.0, 213.0), Coord<double>(-244.0233206221807, -79.22004323127496), Coord<double>(181.0583206221806, -231.04295676872505)
    };
    ASSERT_TRUE(t2 >= t1);
}

TEST(tri_greater_or_eq, test03) {
    Triangle<double> t1 = {
        Coord<double>(0.0, 5.0), Coord<double>(-4.330127018922194, -2.499999999999999), Coord<double>(4.330127018922192, -2.500000000000002)
    };
    Triangle<double> t2 = {
        Coord<double>(5.0, 0.0), Coord<double>(-2.499999999999999, 4.330127018922194), Coord<double>(-2.500000000000002, -4.330127018922192)
    };
    ASSERT_TRUE(t2 >= t1);
}

/*-------------------------------------------TRI_LESS------------------------------------------------------------*/

TEST(tri_less, test01) {
    Triangle<double> t1 = {
        Coord<double>(2.2, 0.0), Coord<double>(-1.0999999999999996, 1.9052558883257653), Coord<double>(-1.100000000000001, -1.9052558883257646)
    };
    Triangle<double> t2 = {
        Coord<double>(4.5, 0.0), Coord<double>(-2.249999999999999, 3.897114317029974), Coord<double>(-2.2500000000000018, -3.8971143170299727)
    };
    ASSERT_TRUE(t1 < t2);
}

TEST(tri_less, test02) {
    Triangle<double> t1 = {
        Coord<double>(4.62, -0.2333234), Coord<double>(-0.07921730041284514, -3.4535822266260965), Coord<double>(5.059217300412844, -5.913094373373904)
    };
    Triangle<double> t2 = {
        Coord<double>(100.0, 213.0), Coord<double>(-244.0233206221807, -79.22004323127496), Coord<double>(181.0583206221806, -231.04295676872505)
    };
    ASSERT_TRUE(t1 < t2);
}

TEST(tri_less, test03) {
    Triangle<double> t1 = {
        Coord<double>(0.0, 5.0), Coord<double>(-4.330127018922194, -2.499999999999999), Coord<double>(4.330127018922192, -2.500000000000002)
    };
    Triangle<double> t2 = {
        Coord<double>(5.0, 0.0), Coord<double>(-2.499999999999999, 4.330127018922194), Coord<double>(-2.500000000000002, -4.330127018922192)
    };
    ASSERT_FALSE(t1 < t2);
}

/*---------------------------------------------TRI_LESS_OR_EQ-----------------------------------------------------*/

TEST(tri_less_or_eq, test01) {
    Triangle<double> t1 = {
        Coord<double>(2.2, 0.0), Coord<double>(-1.0999999999999996, 1.9052558883257653), Coord<double>(-1.100000000000001, -1.9052558883257646)
    };
    Triangle<double> t2 = {
        Coord<double>(4.5, 0.0), Coord<double>(-2.249999999999999, 3.897114317029974), Coord<double>(-2.2500000000000018, -3.8971143170299727)
    };
    ASSERT_TRUE(t1 <= t2);
}

TEST(tri_less_or_eq, test02) {
    Triangle<double> t1 = {
        Coord<double>(4.62, -0.2333234), Coord<double>(-0.07921730041284514, -3.4535822266260965), Coord<double>(5.059217300412844, -5.913094373373904)
    };
    Triangle<double> t2 = {
        Coord<double>(100.0, 213.0), Coord<double>(-244.0233206221807, -79.22004323127496), Coord<double>(181.0583206221806, -231.04295676872505)
    };
    ASSERT_TRUE(t1 <= t2);
}

TEST(tri_less_or_eq, test03) {
    Triangle<double> t1 = {
        Coord<double>(0.0, 5.0), Coord<double>(-4.330127018922194, -2.499999999999999), Coord<double>(4.330127018922192, -2.500000000000002)
    };
    Triangle<double> t2 = {
        Coord<double>(5.0, 0.0), Coord<double>(-2.499999999999999, 4.330127018922194), Coord<double>(-2.500000000000002, -4.330127018922192)
    };
    ASSERT_TRUE(t1 <= t2);
}

/*------------------------------------------TRI_OP_COPY---------------------------------------------------------*/

TEST(tri_op_copy, test01) {
    Triangle<double> t1;
    Triangle<double> t2 = {
        Coord<double>(100.0, 213.0), Coord<double>(-244.0233206221807, -79.22004323127496), Coord<double>(181.0583206221806, -231.04295676872505)
    };
    t1 = t2;
    ASSERT_TRUE(t1 == t2);
}

TEST(tri_op_copy, test02) {
    Triangle<double> t1;
    Triangle<double> t2 = {
        Coord<double>(100.0, 213.0), Coord<double>(-244.0233206221807, -79.22004323127496), Coord<double>(181.0583206221806, -231.04295676872505)
    };
    t2 = t1;
    ASSERT_TRUE(t1 == t2);
}

TEST(tri_op_copy, test03) {
    Triangle<double> t1 = {
        Coord<double>(4.62, -0.2333234), Coord<double>(-0.07921730041284514, -3.4535822266260965), Coord<double>(5.059217300412844, -5.913094373373904)
    };
    Triangle<double> t2 = {
        Coord<double>(100.0, 213.0), Coord<double>(-244.0233206221807, -79.22004323127496), Coord<double>(181.0583206221806, -231.04295676872505)
    };
    t1 = t2;
    ASSERT_TRUE(t1 == t2);
}

/*--------------------------------------------TRI_OP_MOVE---------------------------------------------------------*/

TEST(tri_op_move, test01) {
    Triangle<double> t1;
    Triangle<double> t2 = {
        Coord<double>(100.0, 213.0), Coord<double>(-244.0233206221807, -79.22004323127496), Coord<double>(181.0583206221806, -231.04295676872505)
    };
    Triangle<double> t3(t2);
    t1 = std::move(t2);
    ASSERT_TRUE(t1 == t3);
}

TEST(tri_op_move, test02) {
    Triangle<double> t1;
    Triangle<double> t2 = {
        Coord<double>(100.0, 213.0), Coord<double>(-244.0233206221807, -79.22004323127496), Coord<double>(181.0583206221806, -231.04295676872505)
    };
    Triangle<double> t3(t1);
    t2 = std::move(t1);
    ASSERT_TRUE(t3 == t2);
}

TEST(tri_op_move, test03) {
    Triangle<double> t1 = {
        Coord<double>(4.62, -0.2333234), Coord<double>(-0.07921730041284514, -3.4535822266260965), Coord<double>(5.059217300412844, -5.913094373373904)
    };
    Triangle<double> t2 = {
        Coord<double>(100.0, 213.0), Coord<double>(-244.0233206221807, -79.22004323127496), Coord<double>(181.0583206221806, -231.04295676872505)
    };
    Triangle<double> t3(t2);
    t1 = std::move(t2);
    ASSERT_TRUE(t1 == t3);
}

/*--------------------------------------ARRAY_GET_TOTAL_AREA------------------------------------------------------*/

TEST(array_get_total_area, test01) {
    Triangle<double> t = {
        Coord<double>(4.62, -0.2333234), Coord<double>(-0.07921730041284514, -3.4535822266260965), Coord<double>(5.059217300412844, -5.913094373373904)
    };
    Octagon<double> o = {
        Coord<double>(2.2, 0.0), Coord<double>(1.5556349186104048, 1.5556349186104046), Coord<double>(1.3471114790620887e-16, 2.2), 
        Coord<double>(-1.5556349186104046, 1.5556349186104048), Coord<double>(-2.2, 2.6942229581241775e-16), 
        Coord<double>(-1.555634918610405, -1.5556349186104046), Coord<double>(-4.0413344371862655e-16, -2.2), 
        Coord<double>(1.5556349186104044, -1.555634918610405)
    };
    Hexagon<double> h = {
        Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
        Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)
    };
    Array<std::shared_ptr<Figure<double>>> a = {
        std::make_shared<Triangle<double>>(t),
        std::make_shared<Octagon<double>>(o),
        std::make_shared<Hexagon<double>>(h)
    };
    ASSERT_TRUE(a.get_total_area() == ((double) t + (double) o + (double) h));
}

TEST(array_get_total_area, test02) {
    Array<std::shared_ptr<Figure<double>>> a;
    ASSERT_TRUE(a.get_total_area() == 0);
}

TEST(array_get_total_area, test03) {
    Triangle<double> t1 = {
        Coord<double>(4.62, -0.2333234), Coord<double>(-0.07921730041284514, -3.4535822266260965), Coord<double>(5.059217300412844, -5.913094373373904)
    };
    Triangle<double> t2 = {
        Coord<double>(2.2, 0.0), Coord<double>(-1.0999999999999996, 1.9052558883257653), Coord<double>(-1.100000000000001, -1.9052558883257646)
    };
    Triangle<double> t3 = {
        Coord<double>(100.0, 213.0), Coord<double>(-244.0233206221807, -79.22004323127496), Coord<double>(181.0583206221806, -231.04295676872505)
    };
    Array<std::shared_ptr<Figure<double>>> a = {
        std::make_shared<Triangle<double>>(t1),
        std::make_shared<Triangle<double>>(t2),
        std::make_shared<Triangle<double>>(t3)
    };
    ASSERT_TRUE(a.get_total_area() == ((double) t1 + (double) t2 + (double) t3));
}

/*--------------------------------------ARRAY_REMOVE-------------------------------------------------------------*/

TEST(array_remove, test01) {
    Triangle<double> t = {
        Coord<double>(4.62, -0.2333234), Coord<double>(-0.07921730041284514, -3.4535822266260965), Coord<double>(5.059217300412844, -5.913094373373904)
    };
    Octagon<double> o = {
        Coord<double>(2.2, 0.0), Coord<double>(1.5556349186104048, 1.5556349186104046), Coord<double>(1.3471114790620887e-16, 2.2), 
        Coord<double>(-1.5556349186104046, 1.5556349186104048), Coord<double>(-2.2, 2.6942229581241775e-16), 
        Coord<double>(-1.555634918610405, -1.5556349186104046), Coord<double>(-4.0413344371862655e-16, -2.2), 
        Coord<double>(1.5556349186104044, -1.555634918610405)
    };
    Hexagon<double> h = {
        Coord<double>(2, 0), Coord<double>(1, 1.7320508075688772), Coord<double>(-1, 1.7320508075688772), Coord<double>(-2, 0),
        Coord<double>(-1, -1.7320508075688772), Coord<double>(1, -1.7320508075688772)
    };
    Array<std::shared_ptr<Figure<double>>> a = {
        std::make_shared<Triangle<double>>(t),
        std::make_shared<Octagon<double>>(o),
        std::make_shared<Hexagon<double>>(h)
    };
    a.remove(0);
    ASSERT_TRUE(a.get_size() == 2);
    ASSERT_TRUE(a.get_total_area() == ((double) o + (double) h));
}

TEST(array_remove, test02) {
    Array<std::shared_ptr<Figure<double>>> a;
    ASSERT_ANY_THROW(a.remove(2));
}

TEST(array_remove, test03) {
    Triangle<double> t = {
        Coord<double>(4.62, -0.2333234), Coord<double>(-0.07921730041284514, -3.4535822266260965), Coord<double>(5.059217300412844, -5.913094373373904)
    };
    Array<std::shared_ptr<Figure<double>>> a = {
        std::make_shared<Triangle<double>>(t)
    };
    ASSERT_ANY_THROW(a.remove(1));
}

TEST(array_remove, test04) {
    Triangle<double> t1 = {
        Coord<double>(4.62, -0.2333234), Coord<double>(-0.07921730041284514, -3.4535822266260965), Coord<double>(5.059217300412844, -5.913094373373904)
    };
    Triangle<double> t2 = {
        Coord<double>(2.2, 0.0), Coord<double>(-1.0999999999999996, 1.9052558883257653), Coord<double>(-1.100000000000001, -1.9052558883257646)
    };
    Triangle<double> t3 = {
        Coord<double>(100.0, 213.0), Coord<double>(-244.0233206221807, -79.22004323127496), Coord<double>(181.0583206221806, -231.04295676872505)
    };
    Array<std::shared_ptr<Figure<double>>> a = {
        std::make_shared<Triangle<double>>(t1),
        std::make_shared<Triangle<double>>(t2),
        std::make_shared<Triangle<double>>(t3)
    };
    a.remove(0);
    a.remove(0);
    ASSERT_TRUE(a.get_size() == 1);
    ASSERT_TRUE(a.get_total_area() == (double) t3);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
