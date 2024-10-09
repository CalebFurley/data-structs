#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "exceptions.h"
using std::ostream;

class QueueException : public Exception {};
class QueueOverflow : public QueueException {};
class QueueUnderflow : public QueueException {};
class QueueMemomry : public QueueException {};
//define other exceptions
//implement exceptions throughout class

/*
  Class Explanation here..
*/

template <class DT>
class Queue {
protected:
  int _front; //points to front of queue
  int _rear; //points to end of queue
  int _max; //stores max value of queue
  DT* _data; //stores data of queue
public:
  //Constructors
  Queue();
  Queue(int max);
  ~Queue();

  //Accessors
  DT& peek() const; //peaks at top of queue
  bool isEmpty() const; //checks if queue is empty
  bool isFull() const; //checks if queue is full
  int size() const; //returns the size of the queue       
  int max() const; //returns the max size of the queue

  //Mutators
  void enqueue(DT& object);
  DT& dequeue();

  //Operators
  template <class U>
  friend ostream& operator << (ostream& stream, const Queue<U>& object);
};

#endif