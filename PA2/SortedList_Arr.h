#include <iostream>

const int max_amount = 500;
template <class List_entry>

class ListArr{
public:
	ListArr();
	~ListArr();
	//ListArr(const ListArr<List_entry> &copy); //errors caused program to crash, commenting out to let program run
	
	Error_code insertAr(const List_entry &T);
	Error_code removeAr(List_entry &T);
	Error_code searchAr(const List_entry &T);
	void visitAr(void (*fp) (List_entry &T));
	int sizeAr() const;
	bool emptyAr();
	bool fullAr();
protected:	
	List_entry newArray[max_amount];
	int count;
	int binarySearch(int l, int r, const List_entry &S);
};

template <class List_entry>
int ListArr<List_entry>::binarySearch(int leftPos, int rightPos, const List_entry &S)
{
	//from call, leftPos = 0, rightPos = count - 1;
	int middlePos = (rightPos+leftPos)/2;
	if(leftPos > rightPos){
	return -1;
	}
	else if(newArray[middlePos] == S)
	{
	return middlePos; 
	}
	else if(newArray[middlePos] > S){
	return binarySearch(leftPos, middlePos - 1, S);
	}
	else{
	return binarySearch(middlePos + 1, rightPos, S);
	}
	
}

template <class List_entry>
ListArr<List_entry>::ListArr()
{
	count = 0;
	cout << "Constructor Called. " << endl;
}

template <class List_entry>
ListArr<List_entry>::~ListArr()
{
	cout << "Destructor called. " << endl;
	cout << this << endl;
}

/*template <class List_entry>
ListArr<List_entry>::ListArr(const ListArr<List_entry> &copy)
{
		
	cout << "Copy Constructor Called. " << endl;
		
}*/

template <class List_entry>
int ListArr<List_entry>::sizeAr() const
{
	return count;
}

template <class List_entry>
bool ListArr<List_entry>::emptyAr() 
{
        return count <= 0;
}

template <class List_entry>
bool ListArr<List_entry>::fullAr()
{
        return count >= max_amount;
}

template <class List_entry>
Error_code ListArr<List_entry>::insertAr(const List_entry &T)
{
	if(fullAr()){
	return overflow;
	}
	else{
	newArray[count] = T;
	cout << "count (from insert): " << count << ", input # is " << T <<  endl;
	}
	
	for(int i = 0; i < count; i++){
		if(newArray[i] > newArray[count])
		{
		List_entry temp = newArray[i];
		newArray[i] = newArray[count];
		newArray[count] = temp;
		}
	}	
	count++;
	return success;
}

template <class List_entry>
Error_code ListArr<List_entry>::removeAr(List_entry &T)
{
	int pos;
	if(emptyAr()) return underflow;
	else{
	pos = binarySearch(0, count-1, T);
	}
	cout << "Deleting number " << newArray[pos] << " at pos " << pos << endl;
	for(pos; pos < count; pos++){
	if(pos = count -1){
	cout << endl << "Cannot delete last element " << endl; 
	}
	else newArray[pos] = newArray[pos + 1];
	}
	return success;
	
}

template <class List_entry>
Error_code ListArr<List_entry>::searchAr(const List_entry &T)
{
	int pos;
	pos = binarySearch(0, count-1, T);
	if(pos != -1)
	{
	cout << "Pos = " << pos << endl;
	return success;
	}
	else
	{
	cout << "POs = not found " << endl;
	return success;
	}	
}
template <class List_entry>
void ListArr<List_entry>::visitAr(void (*fp) (List_entry &T))
{
	for(int i = 0; i < count; i++){
	(*fp)(newArray[i]);
	}
}


