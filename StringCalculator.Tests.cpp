#include "StringCalculator.h"
#include <gtest/gtest.h>

// Additional test cases to improve coverage

TEST(StringCalculatorAddTests, EmptyStringInput) {
    EXPECT_EQ(add(""), 0);
}

TEST(StringCalculatorAddTests, SingleNumberInput) {
    EXPECT_EQ(add("5"), 5);
}

TEST(StringCalculatorAddTests, TwoNumbersWithDefaultDelimiters) {
    EXPECT_EQ(add("1,2"), 3);
}

TEST(StringCalculatorAddTests, CustomDelimiter) {
    EXPECT_EQ(add("//;\n1;2"), 3);
}

TEST(StringCalculatorAddTests, NegativeNumbers) {
    try {
        add("1,-2,3");
        FAIL() << "Expected std::runtime_error";
    } catch (const std::runtime_error& e) {
        EXPECT_STREQ("negatives not allowed: -2", e.what());
    } catch (...) {
        FAIL() << "Expected std::runtime_error";
    }
}

TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000) {
    EXPECT_EQ(add("2,1001,5"), 7);
}
