#include <iostream>
#include "../lib/StaticArray.h"

//enumerate so can use (for:each)

int main(int argc, char** argv) {

  StaticArray<int>* array = new StaticArray<int>(10);
    //look into setting = {} to init with values.
  
  //fill array with multiples of five
  for (int i=0; i<array->size(); ++i) 
    (*array)[i] = i*5;

  //printing via loop
  for (int i=0; i<array->size(); ++i) 
    std::cout << (*array)[i] << std::endl;
  
  //printing array via << overload
  std::cout << *array << std::endl;

  delete array;
  return 0;
}
