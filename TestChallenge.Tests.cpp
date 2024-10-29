#include "TestChallenge.h"
#include <gtest/gtest.h>

// Fixture Class

class AddFunctionTest : public ::testing::Test {
protected:
    int result;
    void SetUp() override {
        result = 0;
    }
};

// Simple Test Case
TEST_F(AddFunctionTest, AddsTwoPositiveNumbers) {
    add(3, 4, &result);
    ASSERT_EQ(result, 7);
}

TEST_F(AddFunctionTest, AddsPositiveAndNegativeNumbers) {
    add(5, -2, &result);
    ASSERT_EQ(result, 3);
}

TEST_F(AddFunctionTest, AddsTwoNegativeNumbers) {
    add(-3, -6, &result);
    ASSERT_EQ(result, -9);
}

TEST_F(AddFunctionTest, AddsZero) {
    add(0, 0, &result);
    ASSERT_EQ(result, 0);
}

TEST_F(AddFunctionTest, AddsZeroAndNumber) {
    add(0, 5, &result);
    ASSERT_EQ(result, 5);
}
