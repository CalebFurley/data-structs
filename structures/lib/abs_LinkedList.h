#ifndef ABS_LINKEDLIST_H
#define ABS_LINKEDLIST_H

#include "abs_Exception.h"

class LinkedListException : public Exception {};
class LinkedListMemory : public LinkedListException {};
class LinkedListBounds : public LinkedListException {};
class LinkedListNotFound : public LinkedListException {};
class LinkedListAttachToEmpty : public LinkedListException {};


template <class DataType>
class AbstractLinkedList {
public:
//returns info at the head of linkedlist.
  virtual DataType& info() = 0;      
//returns the next element in linkedlist.
  virtual AbstractLinkedList<DataType>* next() = 0;       
//returns true if empty, false if not.
  virtual bool isEmpty() = 0;          
//adds object to the beginning of linkedlist.                   
  virtual void add (const DataType& object) = 0;  
//sets the next element in the linkedlist.        
  virtual AbstractLinkedList<DataType>* setNext() = 0;    
//TODO Finish up, page 242 of book.
//TODO^^
};

#endif

