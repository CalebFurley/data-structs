// This script goes over inheritance and 
// polymorphism in C++

#include <iostream>

class A
{
public:
  int a;
  void print()
  {
    std::cout << "A" << std::endl;
  }
};

class B : public A
{
public:
  int b;
  void print()
  {
    std::cout << "B" << std::endl;
  }
};

class C : public B
{
public:
  int c;
  void print()
  {
    std::cout << "C" << std::endl;
  }
};


class MyInteger
{
private:
  int m_value = 0;
public:
  MyInteger(int value);
  int operator +(MyInteger);  
};

MyInteger::MyInteger(int value)
  : m_value(value)
{
}

int MyInteger::operator+(MyInteger other_object)
{
  return m_value + other_object.m_value;
}


int main() 
{
  /*
  // Basic Inheritance
  A a;
  B b;
  C c;
  a.print();
  b.print();
  c.print();
  c.a = 1;
  std::cout << c.a << std::endl;
  */

  /*
  // Operator Overloading
  MyInteger first_integer(3);
  MyInteger second_integer(2);

  std::cout << first_integer + second_integer << std::endl;
  */

  // Runtime Polymorphism
  // can you explain runtime polymorphism? 
  // what is the difference between runtime and compile time polymorphism?
  // can you copilt exaplin it? 
  A a;
  B b;
  C c;
  A* ptr = &a;
  ptr->print();
  ptr = &b;
  ptr->print();
  ptr = &c;
  ptr->print();

  delete ptr;
  ptr = nullptr; // this is the way? // this is the way.

  return 0;
}


// go back over inheritance slides to see if I missed anything
// then, go over polymorphism slides
// then, go over virtual functions with the best copilot around
