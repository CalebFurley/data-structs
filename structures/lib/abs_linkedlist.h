#ifndef ABS_LINKEDLIST_H
#define ABS_LINKEDLIST_H

#include "exception.h"

class LinkedListException : public Exception {};
class LinkedListMemory : public LinkedListException {};
class LinkedListBounds : public LinkedListException {};
class LinkedListNotFound : public LinkedListException {};
class LinkedListAttachToEmpty : public LinkedListException {};


template <class DataType>
class AbstractLinkedList {
public:
  virtual DataType& info() = 0;
    //returns he object at the head of the linkedlist
    //or throw a bounds error if the list is empty.
  virtual AbstractLinkedList<DataType>* next() = 0;
    //returns the linkedlist pointed to by the current.
  virtual bool isEmpty() = 0;
    //returns true if the list is empty
    //otherwise returns false
  virtual void add (const DataType& object) = 0;
    //add object to the beginning of the list.
  virtual AbstractLinkedList<DataType>* setNext() = 0;
    //


    //TODO Finish up, page 242 of book.
};

#endif

