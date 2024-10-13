#ifndef STACK_H
#define STACK_H

#include<iostream>
#include "exception.h"
using std::ostream;

class StackException : public Exception {};
class StackOverflow : public StackException {};
class StackUnderflow : public StackException {};
//define other exceptions
//implement exceptions throughout class

template<class DT>
class Stack {
protected:
  int _top; //stores index of array where top of stack is located.
  int _max; //stores the size of the array, which is stack max size.
  DT* _data; //is an array that stores the data of the stack.

public:
  //Constructors.
  Stack(); //default constructor.
  Stack(int max); //constructor with max size of stack.
  Stack(const Stack<DT>& other); //copy constructor.
  ~Stack(); //destructor.

  //Accessors
  bool isEmpty() const; //returns T/F if stack is empty.
  bool isFull() const; //returns T/F if stack is full.
  int size() const; //calculates size of the stack.
  int max() const; //returns max size of the stack.
  const DT& peek() const; //peeks first element of stack.

  //Mutators
  DT& pop() //pops and returns item from top of stack.
  void push(DT& item); //pushes to top of stack.

  //Operators
  Stack<DT>& operator = (const Stack<DT>& other);//asignment deep copy.
  template<class U>
  friend ostream& operator << (ostream& stream, Stack<U> self); //print.
};

#endif