#ifndef QUEUE_QUEUEARR_H
#define QUEUE_QUEUEARR_H


/** TODO For this class
 * write a abstractqueueclass then make this class 
 * inherit from it.
 * 
 * then implement the QueueArr class here..
 */

#include <iostream>
#include "abs_Exception.h"

class QueueException : public Exception {};
class QueueOverflow : public QueueException {};
class QueueUnderflow : public QueueException {};
class QueueMemomry : public QueueException {};
//define other exceptions
//implement exceptions throughout class

template <class DT>
class QueueArr {
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
  void enqueue(DT& object); //enqueues to the rear of the list.
  DT& dequeue(); //dequeues from the front of the list.

  //Operators
  template <class U>
  friend std::ostream& operator << (ostd::stream& stream, const Queue<U>& object);
};

#endif