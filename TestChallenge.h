#include <iostream>
using namespace std;

void add(int x, int y, int* result);{
    *result=x+y;
  cout<<"Sum of "<<x<<":"<<y<<" is "<<result<<endl;
}
