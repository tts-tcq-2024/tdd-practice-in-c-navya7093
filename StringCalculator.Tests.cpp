#include <gtest/gtest.h>
#include "StringCalculator.h"

// Test for an empty input
TEST(StringCalculatorAddTests, ExpectZeroForEmptyInput) {
    int expectedResult = 0;
    const std::string input = "";
    int result = add(input);
    ASSERT_EQ(result, expectedResult);
}

// Test for a single zero input
TEST(StringCalculatorAddTests, ExpectZeroForSingleZero) {
    int expectedResult = 0;
    const std::string input = "0";
    int result = add(input);
    ASSERT_EQ(result, expectedResult);
}

// Test for a single number greater than 1000
TEST(StringCalculatorAddTests, IgnoreNumberGreaterThan1000) {
    int expectedResult = 0;
    const std::string input = "1001";
    int result = add(input);
    ASSERT_EQ(result, expectedResult);
}

// Test for multiple numbers with some greater than 1000
TEST(StringCalculatorAddTests, IgnoreNumbersGreaterThan1000) {
    int expectedResult = 1; // 1 + (numbers greater than 1000 are ignored)
    const std::string input = "1,1001";
    int result = add(input);
    ASSERT_EQ(result, expectedResult);
}

// Test for multiple numbers including a number exactly 1000
TEST(StringCalculatorAddTests, SumWithNumberExactly1000) {
    int expectedResult = 1001; // 1 + 1000
    const std::string input = "1,1000";
    int result = add(input);
    ASSERT_EQ(result, expectedResult);
}

// Test for a single number less than 1000
TEST(StringCalculatorAddTests, SingleNumberLessThan1000) {
    int expectedResult = 999;
    const std::string input = "999";
    int result = add(input);
    ASSERT_EQ(result, expectedResult);
}

// Test for a mix of numbers with some negative numbers
TEST(StringCalculatorAddTests, HandlesNegativeNumbers) {
    int expectedResult = -1; // -1 + 2 (negative numbers are included)
    const std::string input = "-1,2";
    int result = add(input);
    ASSERT_EQ(result, expectedResult);
}

// Test for multiple numbers with a mix of positive and negative
TEST(StringCalculatorAddTests, MixedPositiveAndNegativeNumbers) {
    int expectedResult = 2; // 1 + 2 - 1 (negative number included)
    const std::string input = "1,2,-1";
    int result = add(input);
    ASSERT_EQ(result, expectedResult);
}
