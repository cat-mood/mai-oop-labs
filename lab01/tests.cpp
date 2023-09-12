#include <gtest/gtest.h>
#include "solve.hpp"

TEST(test01, vowels) {
    std::string s = "This website is for losers LOL!";
    delete_vowels(s);
    ASSERT_TRUE("Ths wbst s fr lsrs LL!" == s);
}

TEST(test02, vowels) {
    std::string s = "aeiouAEIOU";
    delete_vowels(s);
    ASSERT_TRUE("" == s);
}

TEST(test03, vowels) {
    std::string s = "bcdBCD";
    delete_vowels(s);
    ASSERT_TRUE("bcdBCD" == s);
}

TEST(test04, vowels) {
    std::string s = "a b c d E?";
    delete_vowels(s);
    ASSERT_TRUE(" b c d ?" == s);
}

TEST(test05, vowels) {
    std::string s = "";
    delete_vowels(s);
    ASSERT_TRUE("" == s);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
