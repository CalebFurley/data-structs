// go over exceptions in C++
#include <iostream>

int main()
{
  try
  {
    throw 20;
  }
  catch(...)  // <---------------- catches all types of exceptions
  {
    std::cout << "An exception occurred." << std::endl;
  }
  //catch (int e)    <----------------- this is the way, handles exceptions of type int
  //{
  //  std::cout << "An exception occurred. Exception Nr. " << e << std::endl;
  //}
  // catch (char const* e)  <----------------- this is the way, handles exceptions of type char const*
  // can catch as many as you like.

  // in future probably if error is thrown, catch it and log it to a file. exactly like the io.cpp example. ;)

  // i just saw rethrowing exceptions, can i do tha recursively? // better not, it will be a mess. i can imagine lol

  return 0;
}