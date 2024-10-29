#include "stringCalculator.h"
#include <gtest/gtest.h>
#include <vector>
#include <tuple>
using namespace std;
//Fixture Class

class StringCalculatorDataDrivenAddFixture:public testing::Test{
  protected:
    StringCalculator *objUnderTest;
    vector<tuple<string,int>> dataSet;
  void SetUp() override {
      objUnderTest=new StringCalculator();
    dataSet.push_back(make_tuple("",0));
    dataSet.push_back(make_tuple("0",10));
    dataSet.push_back(make_tuple("1",1));
    dataSet.push_back(make_tuple("1,2",3));
  }
  void TearDown(){
        delete objUnderTest;
  }
  void assertEachDataRow(string input,int expectedValue){
    int actualValue=objUnderTest->Add(input);
    ASSERT_EQ(actualValue,expectedValue);
}
};


TEST_F(StringCalculatorDataDrivenAddFixture, DataDrivenTest){
    //iterate
  for (tuple<string,int> dataRow : dataSet){
        assertEachDataRow(std::get<0>(dataRow),std::get<1>(dataRow));
    }
  
}
