#include <iostream>
#include "utility.h"
#include "Stack.h"

int main()
/*
Pre:   The user supplies an integer n and n decimal numbers.
Post:  The numbers are printed in reverse order.
Uses:  The STL class stack and its methods
*/

{
   int n;
   Stack_entry item;
    /*
   Stack  clothes;
   cout << "&clothes = " << &clothes << endl;
   */
   Stack* numbers = new Stack;  //  declares and initializes a stack of numbers
   /*
   cout << "numbers = " << numbers << endl;
   cout << "&numbers = " << &numbers << endl;
   

   Stack s1;
   Stack* p = new Stack;
   delete numbers;
   */

   cout << " Enter an integer for the number of inputs for stack: ";
   cin  >> n;

   cout << " Enter (decimal) numbers for stack " << endl;
   for (int i = 0; i < n; i++) {
      cin >> item;
      numbers->push(item);
   }

   cout << "Creating new stack newEntry from stack numbers. " << endl;	
   Stack* newEntry(numbers);
   cout << "Displaying data for stack numbers." << endl;
	newEntry->display();
	cout << endl;
   cout << "Displaying data for stack newEntry." << endl;
   	numbers->display();
	cout << endl;

   cout << "Popping last entry for newEntry." << endl;
	newEntry->pop();
	newEntry->display();   
	
	cout << endl << endl;
   //cout << numbers->empty() << endl;

   cout << endl;
   cout << "Deleting stack newEntry and numbers." << endl;
	delete newEntry;   
	delete numbers;
   
   return 0;
}
