#include "Stack.h"
#include <iostream>

Error_code Stack::push(const Stack_entry &item)
{
  Error_code outcome = success;
   Node* newNode = new Node(item, topNode);  
	topNode = newNode;
  	count++;
	 return outcome;
}


Error_code Stack::pop()
/*
Pre:  None.
Post: If the Stack is not empty, the top of
      the Stack is removed.  If the Stack
      is empty, an Error_code of underflow is returned.
*/

{
   Error_code outcome = success;
   Node* temp = topNode;
   if(topNode != NULL) {
       topNode = topNode->next;
       delete temp;
	count--;
   }
   else
       outcome = underflow;
   return outcome;
}


Error_code Stack::top(Stack_entry &item) const
/*
Pre:  None.
Post: If the Stack is not empty, the top of
      the Stack is returned in item.  If the Stack
      is empty an Error_code of underflow is returned.
*/

{
   Error_code outcome = success;
   item = topNode->entry;
	return outcome;
}


bool Stack::empty() const
/*
Pre:  None.
Post: If the Stack is empty, true is returned.
      Otherwise false is returned.
*/

{
   bool outcome = true;
   return (count == 0);
   /*
   if(count > 0)
       return outcome;
   else
       return !outcome;
       */
}


Stack::Stack()
/*
Pre:  None.
Post: The stack is initialized to be empty.
*/
{
   cout << "Constructor called" << endl;
   topNode = NULL;
	count = 0;
}

Stack::~Stack()
{
    //delete data; //cause a memory leak
    cout << "Destructor called" << endl;
    while(topNode != NULL) 
    {
        Node* temp = topNode;
        topNode = topNode ->next;
        delete temp;
    }

}

Stack::Stack(const Stack& org)
{
    Node* temp = org.topNode;
	if(temp != NULL){ 
         Node* newNode = new Node(temp->entry);
	 topNode = newNode;
	 while(temp->next != NULL){
		temp = temp->next;
		newNode->next = new Node(temp->entry);
		newNode = newNode->next;
	 }
	}
}

Error_code Stack::display(){
	Error_code outcome = success;
	Node* temp = topNode;
	while(topNode != NULL){
	 Stack_entry item;
	 top(item);
	 cout << item << " ";
	topNode = topNode->next;
	}
	topNode = temp;
	return outcome;
	
}
