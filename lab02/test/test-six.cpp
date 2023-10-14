#include <gtest/gtest.h>
#include "six.h"

TEST(eq, test01) {
    Six num1("0"), num2("0");
    ASSERT_TRUE(num1 == num2);
}

TEST(eq, test02) {
    Six num1("100"), num2("25");
    ASSERT_FALSE(num1 == num2);
}

TEST(eq, test03) {
    Six num1, num2("0");
    ASSERT_FALSE(num1 == num2);
}

TEST(eq, test04) {
    Six num1, num2;
    ASSERT_TRUE(num1 == num2);
}


TEST(not_eq, test01) {
    Six num1("21"), num2("21");
    ASSERT_FALSE(num1 != num2);
}

TEST(not_eq, test02) {
    Six num1("23"), num2("1");
    ASSERT_TRUE(num1 != num2);
}

TEST(not_eq, test03) {
    Six num1, num2("0");
    ASSERT_TRUE(num1 != num2);
}

TEST(not_eq, test04) {
    Six num1, num2;
    ASSERT_FALSE(num1 != num2);
}


TEST (greater, test01) {
    Six num1("34"), num2("1");
    ASSERT_TRUE(num1 > num2);
}

TEST(greater, test02) {
    Six num1("145");
    ASSERT_FALSE(num1 > num1);
}

TEST(greater, test03) {
    Six num1("10100"), num2("10010");
    ASSERT_TRUE(num1 > num2);
}

TEST(greater, test04) {
    Six num1("10"), num2("1220");
    ASSERT_FALSE(num1 > num2);
}

TEST(greater, test05) {
    Six num1, num2("1");
    ASSERT_TRUE(num2 > num1);
}



TEST(greater_or_eq, test01) {
    Six num1("34"), num2("1");
    ASSERT_TRUE(num1 >= num2);
}

TEST(greater_or_eq, test02) {
    Six num1("145");
    ASSERT_TRUE(num1 >= num1);
}

TEST(greater_or_eq, test03) {
    Six num1("22"), num2("12");
    ASSERT_TRUE(num1 >= num2);
}

TEST(greater_or_eq, test04) {
    Six num1("10"), num2("1220");
    ASSERT_FALSE(num1 >= num2);
}

TEST(greater_or_eq, test05) {
    Six num1, num2("1");
    ASSERT_TRUE(num2 >= num1);
}



TEST(less, test01) {
    Six num1("34"), num2("1");
    ASSERT_FALSE(num1 < num2);
}

TEST(less, test02) {
    Six num1("145");
    ASSERT_FALSE(num1 < num1);
}

TEST(less, test03) {
    Six num1("10100"), num2("10010");
    ASSERT_FALSE(num1 < num2);
}

TEST(less, test04) {
    Six num1("10"), num2("1220");
    ASSERT_TRUE(num1 < num2);
}

TEST(less, test05) {
    Six num1, num2("1");
    ASSERT_TRUE(num1 < num2);
}



TEST(less_or_eq, test01) {
    Six num1("34"), num2("1");
    ASSERT_FALSE(num1 <= num2);
}

TEST(less_or_eq, test02) {
    Six num1("145");
    ASSERT_TRUE(num1 <= num1);
}

TEST(less_or_eq, test03) {
    Six num1("22"), num2("12");
    ASSERT_FALSE(num1 <= num2);
}

TEST(less_or_eq, test04) {
    Six num1("10"), num2("1220");
    ASSERT_TRUE(num1 <= num2);
}

TEST(less_or_eq, test05) {
    Six num1, num2("1");
    ASSERT_TRUE(num1 <= num2);
}



TEST(add, test01) {
    Six num1("0"), num2("12");
    ASSERT_TRUE(num1 + num2 == Six("12"));
}

TEST(add, test02) {
    Six num1("254"), num2("0");
    ASSERT_TRUE(num1 + num2 == Six("254"));
}

TEST(add, test03) {
    Six num1("40"), num2("1");
    ASSERT_TRUE(num1 + num2 == Six("41"));
}

TEST(add, test04) {
    Six num1("4"), num2("10");
    ASSERT_TRUE(num1 + num2 == Six("14"));
}

TEST(add, test05) {
    Six num1("5"), num2("1");
    ASSERT_TRUE(num1 + num2 == Six("10"));
}

TEST(add, test06) {
    Six num1("40"), num2("12");
    ASSERT_TRUE(num1 + num2 == Six("52"));
}

TEST(add, test07) {
    Six num1("12543125412154215421541251432215"), num2("1352514303240352023505231042301423043201502314012");
    ASSERT_TRUE(num1 + num2 == Six("1352514303240352040452400454500042505143154150231"));
}

TEST(add, test08) {
    Six num1, num2("23");
    ASSERT_TRUE(num1 + num2 == Six("23"));
}



TEST(asgn_add, test01) {
    Six num1("12543125412154215421541251432215"), num2("1352514303240352023505231042301423043201502314012");
    num1 += num2;
    ASSERT_TRUE(num1 == Six("1352514303240352040452400454500042505143154150231"));
}

TEST(asgn_add, test02) {
    Six num1, num2("23");
    num1 += num2;
    ASSERT_TRUE(num1 == Six("23"));
}

TEST(asgn_add, test03) {
    Six num1, num2("23");
    num2 += num1;
    ASSERT_TRUE(num2 == Six("23"));
}




TEST(sub, test01) {
    Six num1("12"), num2("10");
    ASSERT_TRUE(num1 - num2 == Six("2"));
}

TEST(sub, test02) {
    Six num1("5"), num2("1");
    ASSERT_TRUE(num1 - num2 == Six("4"));
}

TEST(sub, test03) {
    Six num1("10"), num2("3");
    ASSERT_TRUE(num1 - num2 == Six("3"));
}

TEST(sub, test04) {
    Six num1("24232"), num2("24232");
    ASSERT_TRUE(num1 - num2 == Six("0"));
}

TEST(sub, test05) {
    Six num1("3"), num2("12");
    ASSERT_ANY_THROW(num1 - num2);
}

TEST(sub, test06) {
    Six num1("12300000000000000000000000000000000000000032320"), num2("555555555555555555");
    ASSERT_TRUE(num1 - num2 == Six("12255555555555555555555555555000000000000032321"));
}

TEST(sub, test07) {
    Six num1("10100"), num2("10010");
    ASSERT_TRUE(num1 - num2 == Six("50"));
}

TEST(sub, test08) {
    Six num1("100"), num2;
    ASSERT_TRUE(num1 - num2 == Six("100"));
}


TEST(asgn_sub, test01) {
    Six num1("12300000000000000000000000000000000000000032320"), num2("555555555555555555");
    num1 -= num2;
    ASSERT_TRUE(num1 == Six("12255555555555555555555555555000000000000032321"));
}

TEST(asgn_sub, test02) {
    Six num1, num2("10");
    num1 += num2;
    ASSERT_TRUE(num1 == Six("10"));
}

TEST(asgn_sub, test03) {
    Six num1, num2("10");
    num2 += num1;
    ASSERT_TRUE(num2 == Six("10"));
}



TEST(assignment, test01) {
    Six num1, num2("23");
    num1 = num2;
    ASSERT_TRUE(num1 == Six("23"));
}

TEST(assignment, test02) {
    Six num1("12"), num2("40");
    num1 = num2;
    ASSERT_TRUE(num1 == num2);
}

TEST(assignment, test03) {
    Six num1, num2;
    num1 = num2;
    ASSERT_TRUE(num1 == num2);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
