#include <iostream>
#include "HTChain.h"
#include "HTOpenAddress.h"
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

void menu(){
	cout << "Usage: $PA4 ht_loadFactorPercentage (45, 55, ... 95)" << endl;
}

int horner(string word, long int size)
{

    int horner = 0;
    for(int i = 0; i < word.length(); i++)
        horner = ((31* horner) + word[i]) % size;
    return horner;
}

int simpleSum(string word, long int size)
{
    unsigned int hash = 0;
    int c;
    const char *wordChar = word.c_str();

    while (c = *wordChar++ )
        hash += c;

    return hash % size;
}


int main(int argc, char* argv[])
{	
	if(argc < 2){
	   menu();
	   exit(1);
	}
	
	int loadFactor = atoi(argv[1]);
	int hash;
	clock_t start, end;
	double times[6];
			
	fstream inFile;
	string Dictionary[58112];
	string Delete[33];

	int i = 0;
	inFile.open("insert.txt");
	while(i < 58112){	
	getline(inFile, Dictionary[i]);
	i++;
	}
	inFile.close();
	
	i = 0;
	inFile.open("delete.txt");
	while(i < 33){
	getline(inFile, Delete[i]);
	i++;
	}
	inFile.close();
	
	i = 0;	
	HTChain<string> A(loadFactor);
	HTChain<string> B(loadFactor);
        HTOpenAddress<string> C(loadFactor);
        HTOpenAddress<string> D(loadFactor);
	HTOpenAddress<string> E(loadFactor);
	HTOpenAddress<string> F(loadFactor);
			

	//hash = horner(Dictionary[i], size); 	
	//cout << "hash example: " << hash << endl;
	long int size;
	size = A.getSize();
	for(int i = 0; i < 58112; i++){
	hash = horner(Dictionary[i], size);
	   start = clock();
	A.insert(Dictionary[i], hash);
	   end = clock();
		times[0] += ((double) (end - start)/CLOCKS_PER_SEC);
	   start = clock();
	C.insert(Dictionary[i], hash, 1);
	   end = clock();
		times[1] += ((double) (end - start)/CLOCKS_PER_SEC);
	   start = clock();
	D.insert(Dictionary[i], hash, 2);
	   end = clock();
		times[2] += ((double) (end - start)/CLOCKS_PER_SEC);
	}
	cout << "*******************HornerMethod********************" << endl;
	A.print();
	 cout << "Time is " << times[0] << endl;
	cout << endl;
	C.print();
	 cout << "Time is " << times[1] << endl;
	cout << endl;
	D.print();	
	 cout << "Time is " << times[2] << endl;
	cout << "***************************************************" << endl;
	cout << endl;
	
	
	size = B.getSize();
	for(int i = 0; i < 58112; i++){
	hash = simpleSum(Dictionary[i], size);
	   start = clock();
	B.insert(Dictionary[i], hash);
	   end = clock();
		times[3] += ((double) (end - start)/CLOCKS_PER_SEC);
	   start = clock();
	E.insert(Dictionary[i], hash, 1);
	   end = clock();
		times[4] += ((double) (end - start)/CLOCKS_PER_SEC);
	   start = clock();
	F.insert(Dictionary[i], hash, 2);
	   end = clock();
		times[5] += ((double) (end - start)/CLOCKS_PER_SEC);
	}
	cout << "******************SimpleSumMethod*****************" << endl;
	B.print();
	 cout << "Time is " << times[3] << endl;
	cout << endl;
	E.print();
	 cout << "Time is " << times[4] << endl;
	cout << endl;
	F.print();
	 cout << "Time is " << times[5] << endl;
	cout << "**************************************************" << endl;
	cout << endl;

	
			

return 0;
}

