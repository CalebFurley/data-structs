#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

class Exception {};
class DivideByZeroException : public Exception {};
class ArrayOutOfBoundsException : public Exception {};
class NegativeIndexException : public Exception {};

#endif