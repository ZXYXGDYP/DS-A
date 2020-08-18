#ifndef HTChain_H
#define HTChain_H
#include "Node.h"
#include "Utility.h"

template <class T>
class HTChain{
private:
	Node<T>** ht;
	double loadFactor;
	int collision;
	long int size;
	double AveCS;
public:
	HTChain();	//work on implememting and testing
	HTChain(int);
	~HTChain();
	Error_code print();
	Error_code insert(T, long int);
	Error_code remove(T&);
	int getSize();	
};

#endif


template <class T>
HTChain<T>::HTChain(){
	size = 10000;
	ht = new Node<T>*[size];
	loadFactor = 0.0;
	collision = 0;
	AveCS = 0;	
}

template <class T>
HTChain<T>::HTChain(int LF){
	
	loadFactor = LF;
	if(loadFactor == 45){size = 129161;}
        else if(loadFactor == 55){size = 105667;}
        else if(loadFactor == 65){size = 89413;}
        else if(loadFactor ==  75){size = 77489;}
        else if(loadFactor == 85){size = 68371;}
        else if(loadFactor == 95){size = 61211;}
        else{size = 58112;};
	ht = new Node<T>*[size];
	collision = 0;
	AveCS = 0;
}

template <class T>
HTChain<T>::~HTChain(){

}

template <class T>
int HTChain<T>::getSize(){
	return size;
}

template <class T>
Error_code HTChain<T>::insert(T x, long int hash){
	
	if(ht[hash] == NULL){
	ht[hash] = new Node<T>(x, NULL);
	ht[hash]->chainSize = 0;
	}
	else{
	collision = collision + 1;
	//cout << "Collision at node " << hash << endl;
	Node<T>* temp = ht[hash];
	ht[hash] = new Node<T>(x, temp);
	ht[hash]->chainSize += 1;
	AveCS++;
	}
	
}

template <class T>
Error_code HTChain<T>::remove(T &y){
	
	return success;
}

template <class T>
Error_code HTChain<T>::print(){
	/*for(int i = start; i < end; i++){
	Node<T> *current = ht[i];
		if(current == NULL){
		cout << "No data" ;
		}
		else{
		while(current!=NULL){
			cout << current->entry;
			current = current->next;
		}
		}
		cout << endl;
	}*/

	AveCS = AveCS / size;
	cout << "------For HTChaining with load factor of " << loadFactor << "-------" << endl;
	cout << "Collision #: " << collision << endl;
	cout << "Average chain size: " << AveCS << endl;
	
}
//used to test if insert worked

