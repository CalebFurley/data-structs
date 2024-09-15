#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
  
  int* intP[10];

  for (int* ip : intP)
  {
    ip = new int(0);
  }

  for (int* ip : intP)
  {
    cout << *ip << endl;
  }

  //need to cleanup dynamically stored data above^^

  //delete *ip <-- values in pointers in array
  //delete[] ip; <-- pointers in array
  //intP nullptr <-- poiner to array

  //delete[] x; <- why x?

  return 0;
}



//project2 below
/*

~chip()
{
  if (!(input1==NULL))      <----this is the recursion!!
    delete input1;
}

compute()
{
  //recursion to check if inputs are NULL or not..
}

//create more chips like
-iteration
-reset-transpose()
-check if the calculation is necessary
-etc

//tag the chips <- know what the chip is


delete[]z


*/
