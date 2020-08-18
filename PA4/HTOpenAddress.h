#ifndef HTOpenAddress_H
#define HTOpenAddress_H
//#include "Utility.h"

template <class T>
class HTOpenAddress{
private:
	Node<T>** ht;
	double loadFactor;
	long int size;
	int probe;
	int totalProbes; 
	int probeType;
public:
	HTOpenAddress();
	HTOpenAddress(int);
	~HTOpenAddress();
	Error_code insert(T, long int, int);
	Error_code remove(T);
	bool isFull();
	Error_code print();
};

#endif

template <class T>
HTOpenAddress<T>::HTOpenAddress(){
	size = 10000;
	ht = new Node<T>*[size];
	loadFactor = 0.0;
	probe = 0;
	totalProbes = 0;
}

template <class T>
HTOpenAddress<T>::HTOpenAddress(int LF){
	loadFactor = LF;
        if(loadFactor == 45){size = 129161;}
        else if(loadFactor == 55){size = 105667;}
        else if(loadFactor == 65){size = 89413;}
        else if(loadFactor ==  75){size = 77489;}
        else if(loadFactor == 85){size = 68371;}
        else if(loadFactor == 95){size = 61211;}
        else{size = 58112;};
	ht = new Node<T>*[size];
	probe = 0;
	totalProbes = 0;
}

template <class T>
HTOpenAddress<T>::~HTOpenAddress(){

}

template <class T>
bool HTOpenAddress<T>::isFull(){
	if(probe > 200){
	return true;
	}
	else
	return false;
}

template <class T>
Error_code HTOpenAddress<T>::insert(T x, long int hash, int pType){
	probeType = pType;
	if(pType == 1){ //Linear
		if(ht[hash] == NULL){
		ht[hash] = new Node<T>(x, NULL);
		ht[hash]->deleted = false;
		}
		else{
		probe = 0;
		while(ht[hash] != NULL && isFull() != true){
			
			if(hash > size)hash = 0;
			hash++;
			probe++;
			totalProbes++;
		}
		ht[hash] = new Node<T>(x, NULL);
		ht[hash]->deleted = false;
		}
	}
	else if(pType == 2){ //Quadratic
		if(ht[hash] == NULL){
		ht[hash] = new Node<T>(x, NULL);
		ht[hash]->deleted = false;
		}
		else{
		int i = 0;
		probe = 0;
		while(ht[hash] != NULL && isFull() != true){
			hash = hash + (i*i);
			if(hash > size)hash = 0;
			i++;	
			probe++;
			totalProbes++;
		}
		ht[hash] = new Node<T>(x, NULL);
		ht[hash]->deleted = false;
		}
	}
	else{
	return success;
	}

}

template <class T>
Error_code HTOpenAddress<T>::remove(T){
	return success;
}

template <class T>
Error_code HTOpenAddress<T>::print(){
	double AveProbe = (double)totalProbes/(double)58112;
	cout << "----For OpenAddressing with load factor of " << loadFactor << "-----" << endl;
	cout << "--------------";
	switch(probeType){
		case 1: cout << "----Linear"; break;
		case 2: cout << "-Quadratic"; break;
	}
	cout << " probing------------------ " << endl;
	cout << "Collision #: " << totalProbes << endl;
	cout << "Average probing: " << AveProbe << endl;
	
}

