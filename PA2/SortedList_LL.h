#include <iostream>

template <class List_entry>

class ListLL {
public:
        ListLL();
        ~ListLL();
        ListLL(const ListLL<List_entry> &copy);

	Error_code insertLL(const List_entry T);
        Error_code removeLL(List_entry &T);
        Error_code searchLL(const List_entry &T);
	void visitLL(void (*fp) (List_entry &T)); 
	int sizeLL() const;
protected:
	int count;
	Node<List_entry> *head;
};

template <class List_entry>
ListLL<List_entry>::ListLL()
{
	head = NULL;
	count = 0;
	cout << "Linked List Created. " << endl;
}

template <class List_entry>
ListLL<List_entry>::~ListLL()
{
	 Node<List_entry> *p, *q;

	for(p = head; p; p = q){
	q = p->next;
	delete p;
	}     
}

template <class List_entry>
ListLL<List_entry>::ListLL(const ListLL<List_entry> &copy)
{
   count = copy.count;

   Node<List_entry> *newNode, *oldHead = copy.head;

   if (oldHead == NULL) head = NULL;
   else {
      newNode = head = new Node<List_entry>(oldHead->entry);
      while (oldHead->next != NULL) {
         oldHead = oldHead->next;
         newNode->next = new Node<List_entry>(oldHead->entry);
         newNode = newNode->next;
      }
   }
	cout << "Copy Constructor Called. " << endl;
}

template <class List_entry>
int ListLL<List_entry>::sizeLL() const{
	return count;
}

template <class List_entry>
Error_code ListLL<List_entry>::insertLL(const List_entry T)
/*
Start if:
Finds the head of the linked list, and if the head is NULL, insert the first item at the head.
else:
sets the current location to head, and while the current location is not NULL, retrieve the item a from
position i. Compare item a to input item T, and if A is smaller move the list down. If a is larger,
insert value T at the position i is at. Insert from List should move the pointers around.
*/
{
	if(head == NULL){
    	head = new Node<List_entry>(T, NULL);
	}
	else if(head->entry > T){
	Node<List_entry> *newNode = new Node<List_entry>(T, head);
	head = newNode;
	}
	else{
	Node<List_entry> *prev = head;
	Node<List_entry> *current = head->next; 
	while(current != NULL){
             	if(current->entry >  T){
		Node<List_entry> *newNode = new Node<List_entry>(T, current);
		prev->next = newNode;
		return success;
		}
                else {
		current = current->next;
		prev = prev->next;	
		}
	}
		if(current == NULL){
                Node<List_entry> *newNode = new Node<List_entry>(T, NULL);
                prev->next = newNode;
		}
        }
	count++;
	return success;

}

template <class List_entry>
Error_code ListLL<List_entry>::removeLL(List_entry &T)
/*
Gets the item located at position x and returns it to variable T from main
parameters in the List remove() function keep range errors and null count errors from happening
*/
{
	if(count == 0)
	return fail;
	else{
	Node<List_entry> *temp = head;
	T = head->entry;
	head = head->next;
	delete temp;
	count--;
	}	
	return success;
	
}

template <class List_entry>
Error_code ListLL<List_entry>::searchLL(const List_entry &T)
/*
Copies the value of T from main and compares it to data from the list, until it either finds the
position and returns it as int x, or goes throught the whole list and returns -1
*/
{
       Node<List_entry> *current;
	int pos = 0;
	current = head->next;
	if(head->entry == T){	
	cout << "Pos " << pos << endl;
	}
	else{
	pos++;
	while(current != NULL){
		if(current->entry == T){
		cout << "Pos " << pos << endl;
		return success;
		}
		else{
		current = current->next;
		pos++;
		}
	}	
	if(current == NULL) 
	cout << "Pos -1 " << endl;
	return success;
	}
}

template <class List_entry>
void ListLL<List_entry>::visitLL(void (*fp) (List_entry &))
{
        Node<List_entry> *n;
	
	for(n = head; n; n = n->next)
		(*fp)(n->entry);
}

