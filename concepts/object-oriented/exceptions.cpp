#include <iostream>
using namespace std;

class DivideByZeroException{};

int main()
{
  int i = 0;
  try 
  {
    if (i==0)
      throw DivideByZeroException();
    else
      cout << 5/i;
  }
  catch(DivideByZeroException exception)
  {
    cout << "Dont divide by zero dummy" << endl;
  }


  return 0;
}