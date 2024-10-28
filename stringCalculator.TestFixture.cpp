#include "stringCalculator.h"
#include <gtest/gtest.h>

class string_calculator_add :  public ::testing::Test{
protected:
    StringCalculator *objUnderTest;
    void SetUp() override
    {
      objUnderTest = new StringCalculator();
    }
    void TearDown() 
    {
      delete objUnderTest;
    }
};

//TEST(TestSuiteName, TestCaseName)
TEST_F(string_calculator_add,positive_cases){
    EXPECT_EQ(objUnderTest->Add(""), 0);
    EXPECT_EQ(objUnderTest->Add("0"), 0);
    EXPECT_EQ(objUnderTest->Add("1"), 0);
    ASSERT_EQ(calculator->Add("1,2"), 3);
  }
