//stack size
#ifndef STACK_H
#define STACK_H
#include "utility.h"
#include "Node.h"
#include <iostream>

const int maxstack = 10;   //  small value for testing

typedef int Stack_entry;

class Stack {
public:
   Stack(); //default constructor
   Stack(const Stack&); //copy constructor
   ~Stack();
   bool empty() const;
   Error_code pop();
   //Error_code top(Stack_entry &) const;
   Error_code top(Stack_entry &) const;
   Error_code push(const Stack_entry &);
   Error_code display();
   int count;
private:
   Node *topNode;
};
#endif

