#include <gtest/gtest.h>
#include "StringCalculator.h"

// Test for empty input
TEST(StringCalculatorTests, EmptyInput) {
    int expectedresult = 0;
    const char* input = "";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

// Test for single number input
TEST(StringCalculatorTests, SingleNumber) {
    int expectedresult = 1;
    const char* input = "1";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

// Test for two numbers separated by comma
TEST(StringCalculatorTests, TwoNumbersWithComma) {
    int expectedresult = 3;
    const char* input = "1,2";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

// Test for newline as delimiter
TEST(StringCalculatorTests, NewlineAsDelimiter) {
    int expectedresult = 6;
    const char* input = "1\n2,3";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

// Test to ignore numbers greater than 1000
TEST(StringCalculatorTests, IgnoreNumbersGreaterThan1000) {
    int expectedresult = 1;
    const char* input = "1,1001";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

// Test for custom delimiter
TEST(StringCalculatorTests, CustomDelimiter) {
    int expectedresult = 3;
    const char* input = "//;\n1;2";
    int result = add(input);
    ASSERT_EQ(result, expectedresult);
}

// Test for negative numbers
TEST(StringCalculatorTests, NegativeNumbers) {
    const char* input = "-1,2,-3";
    try {
        add(input);
        FAIL() << "Expected std::runtime_error for negative numbers";
    } catch (const std::runtime_error& err) {
        ASSERT_STREQ(err.what(), "negatives not allowed: -1, -3");
    } catch (...) {
        FAIL() << "Expected std::runtime_error for negative numbers";
    }
}
