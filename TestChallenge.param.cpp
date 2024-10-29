#include "TestChallenge.h"
#include <gtest/gtest.h>
#include <tuple>
using namespace std;

// Fixture Class
class AddFunctionParameterizedTest : public ::testing::TestWithParam<tuple<int, int, int>> {
protected:
    int result;
    void SetUp() override {
        result = 0;
    }
};

INSTANTIATE_TEST_SUITE_P(
    AddTests,
    AddFunctionParameterizedTest,
    testing::Values(
        make_tuple(3, 4, 7),
        make_tuple(5, -2, 3),
        make_tuple(-3, -6, -9),
        make_tuple(0, 0, 0),
        make_tuple(0, 5, 5)
    )
);

TEST_P(AddFunctionParameterizedTest, HandlesVariousCases) {
    int x = get<0>(GetParam());
    int y = get<1>(GetParam());
    int expected = get<2>(GetParam());

    add(x, y, &result);
    EXPECT_EQ(result, expected);
}

