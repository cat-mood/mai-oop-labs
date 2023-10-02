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
    Six num1("31");
    ASSERT_TRUE(num1 == "31");
}

TEST(eq, test04) {
    Six num1("43");
    ASSERT_FALSE(num1 == "5");
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
    Six num1("322");
    ASSERT_FALSE(num1 != "322");
}

TEST(not_eq, test04) {
    Six num1("10");
    ASSERT_TRUE(num1 != "533");
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
    Six num1("22"), num2("12");
    ASSERT_TRUE(num1 > num2);
}

TEST(greater, test04) {
    Six num1("10"), num2("1220");
    ASSERT_FALSE(num1 > num2);
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



TEST(less, test01) {
    Six num1("34"), num2("1");
    ASSERT_FALSE(num1 < num2);
}

TEST(less, test02) {
    Six num1("145");
    ASSERT_FALSE(num1 < num1);
}

TEST(less, test03) {
    Six num1("22"), num2("12");
    ASSERT_FALSE(num1 < num2);
}

TEST(less, test04) {
    Six num1("10"), num2("1220");
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



TEST(swap, test01) {
    Six num1("130"), num2("21");
    num1.swap(num2);
    ASSERT_TRUE(num1 == "21" && num2 == "130");
}

TEST(swap, test02) {
    Six num1("32"), num2("32");
    num2.swap(num1);
    ASSERT_TRUE(num1 == "32" && num2 == "32");
}



TEST(add, test01) {
    Six num1("0"), num2("12");
    ASSERT_TRUE(num1 + num2 == "12");
}

TEST(add, test02) {
    Six num1("254"), num2("0");
    ASSERT_TRUE(num1 + num2 == "254");
}

TEST(add, test03) {
    Six num1("40"), num2("1");
    ASSERT_TRUE(num1 + num2 == "41");
}

TEST(add, test04) {
    Six num1("4"), num2("10");
    ASSERT_TRUE(num1 + num2 == "14");
}

TEST(add, test05) {
    Six num1("5"), num2("1");
    ASSERT_TRUE(num1 + num2 == "10");
}

TEST(add, test06) {
    Six num1("40"), num2("12");
    ASSERT_TRUE(num1 + num2 == "52");
}

TEST(add, test07) {
    Six num1("12543125412154215421541251432215"), num2("1352514303240352023505231042301423043201502314012");
    ASSERT_TRUE(num1 + num2 == "1352514303240352040452400454500042505143154150231");
}



TEST(sub, test01) {
    Six num1("12"), num2("10");
    ASSERT_TRUE(num1 - num2 == "2");
}

TEST(sub, test02) {
    Six num1("5"), num2("1");
    ASSERT_TRUE(num1 - num2 == "4");
}

TEST(sub, test03) {
    Six num1("10"), num2("3");
    ASSERT_TRUE(num1 - num2 == "3");
}

TEST(sub, test04) {
    Six num1("24232"), num2("24232");
    ASSERT_TRUE(num1 - num2 == "0");
}

TEST(sub, test05) {
    Six num1("3"), num2("12");
    ASSERT_ANY_THROW(num1 - num2);
}

TEST(sub, test06) {
    Six num1("12300000000000000000000000000000000000000032320"), num2("555555555555555555");
    ASSERT_TRUE(num1 - num2 == "12255555555555555555555555555000000000000032321");
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
