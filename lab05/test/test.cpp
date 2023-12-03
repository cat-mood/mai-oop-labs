#include <gtest/gtest.h>
#include "stack.h"
#include "allocator.h"
#include <string>

/*--------------------------STACK_CUSTOM_ALLOC--------------------------------------*/

TEST(stack_custom, test01) {
    lab05::Stack<int, lab05::Allocator<int>> s;
    for (int i = 0; i < 5; ++i) {
        s.push(i);
    }
    ASSERT_EQ(s.size(), 5);
    ASSERT_EQ(s.top(), 4);
    s.pop();
    ASSERT_EQ(s.size(), 4);
    ASSERT_EQ(s.top(), 3);
    for (int i = 0; i < 4; ++i) {
        s.pop();
    }
    ASSERT_EQ(s.size(), 0);
    ASSERT_ANY_THROW(s.pop());
    s.push(1);
    ASSERT_EQ(s.top(), 1);
}

TEST(stack_custom, test02) {
    lab05::Stack<double, lab05::Allocator<double>> s;
    for (int i = 0; i < 5; ++i) {
        s.push(i);
    }
    lab05::Stack<double, lab05::Allocator<double>> other(s);
    ASSERT_EQ(other.size(), s.size());
    ASSERT_DOUBLE_EQ(s.top(), other.top());
}

TEST(stack_custom, test03) {
    lab05::Stack<double, lab05::Allocator<double>> s;
    for (int i = 0; i < 5; ++i) {
        s.push(i);
    }
    lab05::Stack<double, lab05::Allocator<double>> other(std::move(s));
    ASSERT_EQ(other.size(), 5);
    ASSERT_DOUBLE_EQ(s.top(), 4);
}

TEST(stack_custom, test04) {
    lab05::Stack<std::string, lab05::Allocator<std::string>> s;
    s.push(std::string("Meow!!"));
    ASSERT_EQ(s.top(), std::string("Meow!!"));
}

/*----------------------STACK_STL_ALLOC-------------------------------*/

TEST(stack_stl, test01) {
    lab05::Stack<int> s;
    for (int i = 0; i < 5; ++i) {
        s.push(i);
    }
    ASSERT_EQ(s.size(), 5);
    ASSERT_EQ(s.top(), 4);
    s.pop();
    ASSERT_EQ(s.size(), 4);
    ASSERT_EQ(s.top(), 3);
    for (int i = 0; i < 4; ++i) {
        s.pop();
    }
    ASSERT_EQ(s.size(), 0);
    ASSERT_ANY_THROW(s.pop());
    s.push(1);
    ASSERT_EQ(s.top(), 1);
}

TEST(stack_stl, test02) {
    lab05::Stack<double> s;
    for (int i = 0; i < 5; ++i) {
        s.push(i);
    }
    lab05::Stack<double> other(s);
    ASSERT_EQ(other.size(), s.size());
    ASSERT_DOUBLE_EQ(s.top(), other.top());
}

TEST(stack_stl, test03) {
    lab05::Stack<double> s;
    for (int i = 0; i < 5; ++i) {
        s.push(i);
    }
    lab05::Stack<double> other(std::move(s));
    ASSERT_EQ(other.size(), 5);
    ASSERT_DOUBLE_EQ(s.top(), 4);
}

TEST(stack_stl, test04) {
    lab05::Stack<std::string> s;
    std::string str("Meow!!");
    s.push(str);
    ASSERT_EQ(s.top(), std::string("Meow!!"));
}

/*-----------------------ITER----------------------------------------*/

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
