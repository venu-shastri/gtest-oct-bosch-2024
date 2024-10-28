#include "stringCalculator.h"
#include <gtest/gtest.h>

//TEST(TestSuiteName, TestCaseName)
TEST(string_calculator_add,when_passed_a_single_number_returns_0_for_Empty){
  //Arrange
  StringCalculator objUnderTest;
  string input="";
  int expectedValue=0;

  //Act
  int actualValue=objUnderTest.Add(input);

  //ASSERT
  ASSERT_EQ(expectedValue,actualValue);
  }

//TEST(TestSuiteName, TestCaseName)
TEST(string_calculator_add,when_passed_a_single_number_returns_0_for_0){
  //Arrange
  StringCalculator objUnderTest;
  string input="0";
  int expectedValue=0;

  //Act
  int actualValue=objUnderTest.Add(input);

  //ASSERT
  ASSERT_EQ(expectedValue,actualValue);
  }

//TEST(TestSuiteName, TestCaseName)
TEST(string_calculator_add,when_passed_a_single_number_returns_1_for_1){
  //Arrange
  StringCalculator objUnderTest;
  string input="1";
  int expectedValue=1;

  //Act
  int actualValue=objUnderTest.Add(input);

  //ASSERT
  ASSERT_EQ(expectedValue,actualValue);
  }

TEST(string_calculator_add, ReturnsTheSumForTwoCommaDelimitedNumbers) {
    StringCalculator objUnderTest;
    string input="1,2";
    int expectedValue=3;

  //Act
  int actualValue=objUnderTest.Add(input);

  //ASSERT
  ASSERT_EQ(expectedValue,actualValue);
}

TEST(string_calculator_add, ReturnsTheSumForMultipleCommaDelimitedNumbers) {
    StringCalculator objUnderTest;
    string input="1,2,3";
    int expectedValue=6;

  //Act
  int actualValue=objUnderTest.Add(input);

  //ASSERT
  ASSERT_EQ(expectedValue,actualValue);
}

TEST_F(string_calculator_add, ReturnsTheSumForNewlineAndCommaDelimitedNumbers) {
    StringCalculator objUnderTest;
    string input="1\n2,3";
    int expectedValue=6;

  //Act
  int actualValue=objUnderTest.Add(input);

  //ASSERT
  ASSERT_EQ(expectedValue,actualValue);
}

TEST_F(string_calculator_add, ReturnsTheSumBasedOnCustomDelimiter) {
    StringCalculator objUnderTest;
  string input="//;\n1;2";
    int expectedValue=3;

  //Act
  int actualValue=objUnderTest.Add(input);

  //ASSERT
  ASSERT_EQ(expectedValue,actualValue);
}

TEST(string_calculator_add, ThrowsExceptionForNegativeNumbers) {
    StringCalculator objUnderTest;

    try {
        objUnderTest.Add("1,-2,-4,5");
        FAIL() << "Expected std::invalid_argument";
    } catch (std::invalid_argument const &err) {
        ASSERT_EQ(err.what(), std::string("Negatives not allowed: -2,-4"));
    } catch (...) {
        FAIL() << "Expected std::invalid_argument";
    }
}

TEST(string_calculator_add, IgnoresNumbersOver1000) {
    StringCalculator objUnderTest;
  string input="42,1001,3";
    int expectedValue=45;

  //Act
  int actualValue=objUnderTest.Add(input);

  //ASSERT
  ASSERT_EQ(expectedValue,actualValue);
}

TEST(string_calculator_add, UsesMulticharacterDelimiter) {
    StringCalculator objUnderTest;
  string input="//[***]\n8***2***3";
    int expectedValue=13;

  //Act
  int actualValue=objUnderTest.Add(input);

  //ASSERT
  ASSERT_EQ(expectedValue,actualValue);
}

TEST(string_calculator_add, SumsOnEachCustomDelimiter) {
    StringCalculator objUnderTest;
  string input="//[*][%]\n4*2%3";
    int expectedValue=9;

  //Act
  int actualValue=objUnderTest.Add(input);

  //ASSERT
  ASSERT_EQ(expectedValue,actualValue);
}

TEST(string_calculator_add, SumsOnEachMulticharacterDelimiter) {
    StringCalculator objUnderTest;
  string input="//[**][%^]\n4**1%^9";
    int expectedValue=14;

  //Act
  int actualValue=objUnderTest.Add(input);

  //ASSERT
  ASSERT_EQ(expectedValue,actualValue);
}
