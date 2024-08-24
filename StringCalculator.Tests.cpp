#include <gtest/gtest.h>
#include "StringCalculator.h"

TEST(StringCalculatorAddTests, ExpectZeroForEmptyInput) {
    int expectedResult = 0;
    const char* input = "";
    int result = add(input);
    ASSERT_EQ(result, expectedResult);
}
TEST(StringCalculatorAddTests, ExpectZeroForSingleZero) {
    int expectedResult = 0;
    const char* input = "0";
    int result = add(input);
    ASSERT_EQ(result, expectedResult);
}
