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
TEST(StringCalculatorAddTests, ExpectSumForTwoNumbers) {
    int expectedresult = 3;
    const char*  input = "1,2";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}
TEST(StringCalculatorAddTests, ExpectSumWithNewlineDelimiter) {
    int expectedresult = 6;
    const char*  input = "1\n2,3";
    int result =add(input);
    ASSERT_EQ(result, expectedresult);
}
// Test case to cover the missing branch where both conditions are true
TEST(StringCalculatorAddTests, ExpectSumForNoDelimiter) {
    int expectedresult = 7;
    const char* input = "7";  // A string without comma or newline
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}
TEST(StringCalculatorAddTests, ExpectSumForBothCommaAndNewline) {
    int expectedresult = 6;
    const char* input = "1,2\n3";  // String with both a comma and newline
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

