#include "StringCalculator.h"
#include <gtest/gtest.h>
#include <vector>
#include <tuple>
using namespace std;
//Fixture Class

class StringCalculatorDataDrivenAddFixture:public testing::Test{
  protected:
    StringCalculator *objUnderTest;
  void SetUp() override {
      objUnderTest=new StringCalculator();
  }
  void TearDown(){
        delete objUnderTest;
  }
};

void assertEachDataRow(string input,int expectedValue){
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}
TEST_F(StringCalculatorDataDrivenAddFixture, DataDrivenTest){
    vector<tuple<string,int>> dataSet;
    dataSet.push_back(make_tuple("",0));
    dataSet.push_back(make_tuple("0",0));
    dataSet.push_back(make_tuple("1",1));
    dataSet.push_back(make_tuple("1,2",3));
    //iterate
  for (tuple<string,int> dataRow : dataSet){
        assertEachDataRow(dataRow.get<string>(0),dataRow.get<int>(1));
    }
  
}
