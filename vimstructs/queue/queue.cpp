#include <iostream>

int main()
{
  int front = 0;
  int rear = 0;
  
  std::cout << front << std::endl;

  for (int i=0; i<20; ++i)
  {
    front = (front+1)%8;
    std::cout << front << std::endl;
  }

  return 0;
}
