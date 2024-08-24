#include <gtest/gtest.h>
#include "StringCalculator.h"

TEST(StringCalculatorAddTests, ExpectZeroForEmptyInput) {
    int expectedResult = 0;
    const std::string input = "";
    int result = add(input);
    ASSERT_EQ(result, expectedResult);
}

TEST(StringCalculatorAddTests, ExpectZeroForSingleZero) {
    int expectedResult = 0;
    const std::string input = "0";
    int result = add(input);
    ASSERT_EQ(result, expectedResult);
}

TEST(StringCalculatorAddTests, SingleNumberLessThan1000) {
    int expectedResult = 999;
    const std::string input = "999";
    int result = add(input);
    ASSERT_EQ(result, expectedResult);
}

TEST(StringCalculatorAddTests, SingleNumberExactly1000) {
    int expectedResult = 1000;
    const std::string input = "1000";
    int result = add(input);
    ASSERT_EQ(result, expectedResult);
}

TEST(StringCalculatorAddTests, IgnoreNumberGreaterThan1000) {
    int expectedResult = 1; // Expecting 1 because 1001 is ignored
    const std::string input = "1,1001";
    int result = add(input);
    ASSERT_EQ(result, expectedResult);
}

TEST(StringCalculatorAddTests, SumWithNumberExactly1000) {
    int expectedResult = 1001; // 1 + 1000
    const std::string input = "1,1000";
    int result = add(input);
    ASSERT_EQ(result, expectedResult);
}

TEST(StringCalculatorAddTests, HandlesNegativeNumbers) {
    int expectedResult = -1; // Negative numbers included in sum
    const std::string input = "-1,2";
    int result = add(input);
    ASSERT_EQ(result, expectedResult);
}

TEST(StringCalculatorAddTests, MixedPositiveAndNegativeNumbers) {
    int expectedResult = 2; // 1 + 2 - 1
    const std::string input = "1,2,-1";
    int result = add(input);
    ASSERT_EQ(result, expectedResult);
}

TEST(StringCalculatorAddTests, MultipleNumbersWithSomeGreaterThan1000) {
    int expectedResult = 3; // 1 + 2 (1001 is ignored)
    const std::string input = "1,2,1001";
    int result = add(input);
    ASSERT_EQ(result, expectedResult);
}
